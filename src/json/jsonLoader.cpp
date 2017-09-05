#include "json/jsonLoader.h"

namespace json {

jsonLoader::jsonLoader()
{

};

jsonLoader::~jsonLoader()
{
    delete J;
}

jsonLoader::jsonLoader(const char* path)
{
    load(path);
}

void jsonLoader::load(const char* path)
{
    fin=new ifstream;
    fin->open(path);
    J=new jsonNode;
    try
    {
        line=1;
        if(fin->eof()==0)
        {
            nextCharacter();
            read(J);
            if(output==2)
            {
                write(J,0);
            }
        }
        else throw "File is empty";
    }
    catch(string x)
    {
        cout<<x;
    }
    fin->close();
    delete fin;
}

void jsonLoader::nextCharacter()
{
    fin->get(c);
    if(c=='\n')
        line++;
    if(output==1)
        cout<<c;
    clearSpaces();
}

string jsonLoader::sendError(string errorNumber,int value)
{
    string str;

    str+="Line ";
    str+=intTostring(line);
    str+=string(": ");
    str+=errorNumber;
    str+=": Expected ";
    str+="null value";
    str+="\n";

    return str;
}

string jsonLoader::sendError(string errorNumber,bool value)
{
    string str;

    str+="Line ";
    str+=intTostring(line);
    str+=string(": ");
    str+=errorNumber;
    str+=": Expected ";
    str+="bool value";
    str+="\n";

    return str;
}

string jsonLoader::sendError(string errorNumber,string chars)
{
    int i;
    string str;

    str+="Line ";
    str+=intTostring(line);
    str+=string(": ");
    str+=errorNumber;
    str+=": Expected ";
    for(i=0;i<chars.size()-1;i++)
    {
        str+="\'";
        str+=chars[i];
        str+="\'";
        str+=" or ";
    }
    str+="\'";
    str+=chars[i];
    str+="\'\n";

    return str;
}

void jsonLoader::read(jsonNode* J)
{
    string name;

    while(c!=0)
    {
        if(c=='{')
        {
            nextCharacter();
            while(c!=0)
            {
                if(c=='}')
                {
                    nextCharacter();
                    return;
                }
                else if(c=='"')
                {
                    fin->get(c);
                    if(c=='\n')
                        line++;
                    name=getCharactersUntill('"');

                    nextCharacter();
                    if(c==':')
                    {
                        J->son.push_back(deque<jsonNode>());
                        J->son[J->son.size()-1].push_back(jsonNode());
                        J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1].text=name;

                        nextCharacter();
                        if(c=='{')
                        {
                            read(&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1]);
                            if(c==',')
                            {
                                nextCharacter();
                                continue;
                            }
                            else if(c=='}')
                            {
                                nextCharacter();
                                return;
                            }
                            else
                            {
                                throw sendError("Error 1",string(",}"));
                            }
                        }
                        else if(c=='[')
                        {
                            read(&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1]);
                            if(c==',')
                            {
                                nextCharacter();
                                continue;
                            }
                            else if(c=='}')
                            {
                                nextCharacter();
                                return;
                            }
                            else
                            {
                                throw sendError("Error 2",string(",}"));
                            }
                        }
                        else if(c=='"')
                        {
                            fin->get(c);
                            if(c=='\n')
                                line++;
                            name=string("\"")+getCharactersUntill('"')+string("\"");

                            jsonNode* S=&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1];
                            S->son.push_back(deque<jsonNode>());
                            S->son[S->son.size()-1].push_back(jsonNode());
                            S->son[S->son.size()-1][S->son[S->son.size()-1].size()-1].text=name;

                            nextCharacter();
                            if(c==',')
                            {
                                nextCharacter();
                                continue;
                            }
                            else if(c=='}')
                            {
                                nextCharacter();
                                return;
                            }
                            else
                            {
                                throw sendError("Error 3",string(",}"));
                            }
                        }
                        else if(c>='0'&&c<='9')
                        {
                            name=getNumber();
                            clearSpaces();

                            jsonNode* S=&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1];
                            S->son.push_back(deque<jsonNode>());
                            S->son[S->son.size()-1].push_back(jsonNode());
                            S->son[S->son.size()-1][S->son[S->son.size()-1].size()-1].text=name;

                            if(c==',')
                            {
                                nextCharacter();
                                continue;
                            }
                            else if(c=='}')
                            {
                                nextCharacter();
                                return;
                            }
                            else
                            {
                                throw sendError("Error 4",string(",}"));
                            }
                        }
                        else if(c=='t')
                        {
                            name=getCharactersUntill(" \t\n,}]");
                            if(c==' '||c=='\t'||c=='\n')
                                nextCharacter();
                            if(name=="true")
                            {
                                jsonNode* S=&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1];
                                S->son.push_back(deque<jsonNode>());
                                S->son[S->son.size()-1].push_back(jsonNode());
                                S->son[S->son.size()-1][S->son[S->son.size()-1].size()-1].text=name;
                                if(c==',')
                                {
                                    nextCharacter();
                                    continue;
                                }
                                else if(c=='}')
                                {
                                    nextCharacter();
                                    return;
                                }
                                else
                                {
                                    throw sendError("Error 5",string(",}"));
                                }
                            }
                            else
                            {
                                throw sendError("Error 6",true);
                            }
                        }
                        else if(c=='f')
                        {
                            name=getCharactersUntill(" \t\n,}]");
                            if(c==' '||c=='\t'||c=='\n')
                                nextCharacter();
                            if(name=="false")
                            {
                                jsonNode* S=&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1];
                                S->son.push_back(deque<jsonNode>());
                                S->son[S->son.size()-1].push_back(jsonNode());
                                S->son[S->son.size()-1][S->son[S->son.size()-1].size()-1].text=name;
                                if(c==',')
                                {
                                    nextCharacter();
                                    continue;
                                }
                                else if(c=='}')
                                {
                                    nextCharacter();
                                    return;
                                }
                                else
                                {
                                    throw sendError("Error 7",string(",}"));
                                }
                            }
                            else
                            {
                                throw sendError("Error 8",false);
                            }
                        }
                        else if(c=='n')
                        {
                            name=getCharactersUntill(" \t\n,}]");
                            if(c==' '||c=='\t'||c=='\n')
                                nextCharacter();
                            if(name=="null")
                            {
                                jsonNode* S=&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1];
                                S->son.push_back(deque<jsonNode>());
                                S->son[S->son.size()-1].push_back(jsonNode());
                                S->son[S->son.size()-1][S->son[S->son.size()-1].size()-1].text=name;
                                if(c==',')
                                {
                                    nextCharacter();
                                    continue;
                                }
                                else if(c=='}')
                                {
                                    nextCharacter();
                                    return;
                                }
                                else
                                {
                                    throw sendError("Error 9",string(",}"));
                                }
                            }
                            else
                            {
                                throw sendError("Error 10",NULL);
                            }
                        }
                        else
                        {
                            throw sendError("Error 11",string("\"0123456789tfn{["));
                        }
                    }
                    else
                    {
                        throw sendError("Error 12",string(":"));
                    }
                }
                else
                {
                    throw sendError("Error 13",string("\"}"));
                }
            }
        }
        else if(c=='[')
        {
            nextCharacter();

            J->son.push_back(deque<jsonNode>());
            while(1)
            {
                if(c=='[')
                {
                    J->son[J->son.size()-1].push_back(jsonNode());
                    read(&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1]);
                    if(c==',')
                    {
                        nextCharacter();
                        continue;
                    }
                    else if(c==']')
                    {
                        nextCharacter();
                        return;
                    }
                    else
                    {
                        throw sendError("Error 14",string(",]"));
                    }
                }
                else if(c=='{')
                {
                    if(J->text.size()>0)
                    {
                        J->son[J->son.size()-1].push_back(jsonNode());
                        read(&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1]);
                        if(c==',')
                        {
                            nextCharacter();
                            continue;
                        }
                        else if(c==']')
                        {
                            nextCharacter();
                            return;
                        }
                        else
                        {
                            throw sendError("Error 15",string(",]"));
                        }
                    }
                    else
                    {
                        throw string("Line ")+intTostring(line)+string(": Element name should be inherited from array name but doesnt exist\n");
                    }
                }
                else if(c=='"')
                {
                    fin->get(c);
                    if(c=='\n')
                        line++;
                    name=getCharactersUntill('"');

                    J->son[J->son.size()-1].push_back(jsonNode());
                    J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1].text=name;

                    nextCharacter();
                    if(c==',')
                    {
                        nextCharacter();
                        continue;
                    }
                    else if(c==']')
                    {
                        nextCharacter();
                        return;
                    }
                    else if(c==':')
                    {
                        ///BUG NR3 STERGE AICI ,REPARA ERORILE
                        nextCharacter();
                        read(&J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1]);
                        if(c==',')
                        {
                            nextCharacter();
                            continue;
                        }
                        else if(c==']')
                        {
                            nextCharacter();
                            return;
                        }
                        else
                        {
                            throw sendError("Error 16",string(",]"));
                        }
                    }
                    else
                    {
                        throw sendError("Error 17",string(",]:"));
                    }
                }
                else if(c>='0'&&c<='9')
                {
                    name=getNumber();
                    clearSpaces();
                    J->son[J->son.size()-1].push_back(jsonNode());
                    J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1].text=name;
                    if(c==',')
                    {
                        nextCharacter();
                        continue;
                    }
                    else if(c==']')
                    {
                        nextCharacter();
                        return;
                    }
                    else
                    {
                        throw sendError("Error 18",string(",]"));
                    }
                }
                else if(c=='t')
                {
                    name=getCharactersUntill(" \t\n,}]");
                    if(c==' '||c=='\t'||c=='\n')
                        nextCharacter();
                    if(name=="true")
                    {
                        J->son.push_back(deque<jsonNode>());
                        J->son[J->son.size()-1].push_back(jsonNode());
                        J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1].text=name;
                        if(c==',')
                        {
                            nextCharacter();
                            continue;
                        }
                        else if(c==']')
                        {
                            nextCharacter();
                            return;
                        }
                        else
                        {
                            throw sendError("Error 19",string(",]"));
                        }
                    }
                    else
                    {
                        throw sendError("Error 20",true);
                    }
                }
                else if(c=='f')
                {
                    name=getCharactersUntill(" \t\n,}]");
                    if(c==' '||c=='\t'||c=='\n')
                        nextCharacter();
                    if(name=="false")
                    {
                        J->son.push_back(deque<jsonNode>());
                        J->son[J->son.size()-1].push_back(jsonNode());
                        J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1].text=name;
                        if(c==',')
                        {
                            nextCharacter();
                            continue;
                        }
                        else if(c==']')
                        {
                            nextCharacter();
                            return;
                        }
                        else
                        {
                            throw sendError("Error 21",string(",]"));
                        }
                    }
                    else
                    {
                        throw sendError("Error 22",false);
                    }
                }
                else if(c=='n')
                {
                    name=getCharactersUntill(" \t\n,}]");
                    if(c==' '||c=='\t'||c=='\n')
                        nextCharacter();
                    if(name=="null")
                    {
                        J->son.push_back(deque<jsonNode>());
                        J->son[J->son.size()-1].push_back(jsonNode());
                        J->son[J->son.size()-1][J->son[J->son.size()-1].size()-1].text=name;
                        if(c==',')
                        {
                            nextCharacter();
                            continue;
                        }
                        else if(c==']')
                        {
                            nextCharacter();
                            return;
                        }
                        else
                        {
                            throw sendError("Error 23",string(",]"));
                        }
                    }
                    else
                    {
                        throw sendError("Error 24",0);
                    }
                }
                else if(c==']')
                {
                    nextCharacter();
                    return;
                }
                else
                {
                    throw sendError("Error 25",string("\"[]{tfn0123456789"));
                }
            }
        }
    }
}

string jsonLoader::intTostring(int x)
{
    int i,aux;
    string str;

    while(x>0)
    {
        str+=x%10+'0';
        x=x/10;
    }

    for(i=0;i<str.size()/2;i++)
    {
        aux=str[str.size()-1-i];
        str[str.size()-1-i]=str[i];
        str[i]=aux;
    }
    return str;
}

void jsonLoader::write(jsonNode *J,int level)
{
    int i,j,k;

    for(k=0;k<level;k++)
        cout<<char(9);
    if(J->text.size()==0)
        cout<<"___"<<'\n';
    else cout<<J->text<<'\n';

    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            write(&J->son[i][j],level+1);
        }
}

string jsonLoader::clearSpaces()
{
    string str;
    while((c==' '||c=='\n'||c==9)&&fin->eof()==0)
    {
        str+=c;
        fin->get(c);
        if(c=='\n')
            line++;
        if(output==1)
            cout<<c;
    }
    return str;
}

string jsonLoader::getNumber()
{
    string str;

    while((c>='0'&&c<='9')&&fin->eof()==0)
    {
        str+=c;
        fin->get(c);
        if(c=='\n')
            line++;
        if(output==1)
            cout<<c;
    }
    return str;
}

string jsonLoader::getCharactersUntill(char character)
{
    string str;

    while(c!=character&&fin->eof()==0)
    {
        if(output==1)
            cout<<c;
        if(c==character)
        {
            return str;
        }
        str+=c;
        fin->get(c);
        if(c=='\n')
            line++;
    }
    return str;
}

string jsonLoader::getCharactersUntill(const char* characters)
{
    int i;
    string str;

    while(fin->eof()==0)
    {
        if(output==1)
            cout<<c;
        if(c=='\n')
            line++;
        for(i=0;characters[i]!=0;i++)
            if(c==characters[i])
                return str;
        str+=c;
        fin->get(c);
    }
    return str;
}

} // namespace json
