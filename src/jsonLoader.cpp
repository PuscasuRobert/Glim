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
    read(&J);
    write(&J,0);
}

void jsonLoader::read(jsonNode* J)
{
    string name;

    while(fin.eof()==0)
    {
        getCharacters('{');
        fin.get(c);
        getCharacters('"');
        name=getCharacters('"',2);
        getCharacters(':');


        J->son.push_back(deque<jsonNode>());
        J->son[J->son.size()-1].resize(1);
        J->son[J->son.size()-1][0].text=name;

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


string jsonLoader::getCharacters(char character,int nr)
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
    }
}

string jsonLoader::getCharacters(const char* characters,int nr)
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
            }
        if(ok==0)
            str+=c;
        fin.get(c);
    }
}
