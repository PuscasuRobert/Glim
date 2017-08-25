#include "jsonLoader.h"

jsonLoader::jsonLoader()
{

};

jsonLoader::jsonLoader(const char* path)
{
    load(path);
}

void jsonLoader::load(const char* path)
{
    fin.open(path);
    getCharactersUntill('{');
    read(&J);
    if(output==2)
        write(&J,0);
}

void jsonLoader::read(jsonNode* J)
{
    string name;

    while(fin.eof()==0)
    {
        getCharactersUntill('"');
        name=getCharactersUntill('"',2);
        getCharactersUntill(':');
        if(c==':')
        {
            clearSpaces();
            if(c=='{')
            {
                clearSpaces();
                J->son.push_back(deque<jsonNode>());
                J->son[J->son.size()-1].resize(1);
                J->son[J->son.size()-1][0].text=name;
                read(&J->son[J->son.size()-1][0]);
                fin.get(c);
                if(output==1)
                    cout<<c;
                getCharactersUntill(",}]");
                if(c=='}')
                    return;
                if(c==']')
                    return;
                else if(c==',')
                    continue;
            }
            else if(c=='[')
            {
                clearSpaces();
                J->son.push_back(deque<jsonNode>());
                J->son[J->son.size()-1].resize(J->son[J->son.size()-1].size()+1);
                J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1].text=name;
                read(&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1]);
                ///AICI
            }
            else if(c=='"')
            {
                J->son.push_back(deque<jsonNode>());
                J->son[J->son.size()-1].resize(1);
                J->son[J->son.size()-1][0].text=name;

                getCharactersUntill('"');
                name=getCharactersUntill('"',2);
                getCharactersUntill(",}]");

                jsonNode* S=&J->son[J->son.size()-1][0];

                S->son.push_back(deque<jsonNode>());
                S->son[S->son.size()-1].resize(1);
                S->son[S->son.size()-1][0].text=name;

                if(c==',')
                {
                    continue;
                }
                else if(c=='}')
                {
                    return;
                }
            }
            else if(c>='0'&&c<='9')
            {
                J->son.push_back(deque<jsonNode>());
                J->son[J->son.size()-1].resize(1);
                J->son[J->son.size()-1][0].text=name;

                name=getCharactersWhile("1234567890");
                clearSpaces();

                jsonNode* S=&J->son[J->son.size()-1][0];

                S->son.push_back(deque<jsonNode>());
                S->son[S->son.size()-1].resize(1);
                S->son[S->son.size()-1][0].text=name;

                if(c==',')
                    continue;
                else if(c=='}')
                    return;
                else if(c==']')
                    return;
            }
        }
    }
}

void jsonLoader::write(jsonNode *J,int level)
{
    int i,j,k;

    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            for(k=0;k<level;k++)
                cout<<char(9);

            cout<<J->son[i][j].text<<'\n';
            write(&J->son[i][j],level+1);
        }
}

string jsonLoader::getCharactersWhile(const char* characters)
{
    int i;
    string str;

    while(fin.eof()==0)
    {
        bool ok=0;
        for(i=0;characters[i]!=0;i++)
            if(characters[i]==c)
            {
                ok=1;
                break;
            }
        if(ok==1)
            str+=c;
        else return str;
        fin.get(c);
        if(output==1)
            cout<<c;
    }
    return str;
}

string jsonLoader::clearSpaces()
{
    string str;
    fin.get(c);
    if(output==1)
        cout<<c;
    while((c==' '||c=='\n'||c==9)&&fin.eof()==0)
    {
        str+=c;
        fin.get(c);
        if(output==1)
            cout<<c;
    }
    return str;
}


string jsonLoader::getCharactersUntill(char character,int nr)
{
    int nrCurrent=0;
    string str;

    while(fin.eof()==0)
    {
        bool ok=0;
        if(c==character)
        {
            nrCurrent++;
            if(nrCurrent==nr)
                return str;
            ok=1;
        }
        if(ok==0)
            str+=c;
        fin.get(c);
        if(output==1)
            cout<<c;
    }
}

string jsonLoader::getCharactersUntill(const char* characters,int nr)
{
    int i;
    int nrCurrent=0;
    string str;

    while(fin.eof()==0)
    {
        bool ok=0;
        for(i=0;characters[i]!=0;i++)
            if(c==characters[i])
            {
                nrCurrent++;
                if(nrCurrent==nr)
                    return str;
                ok=1;
                break;
            }
        if(ok==0)
            str+=c;
        fin.get(c);
        if(output==1)
            cout<<c;
    }
}
