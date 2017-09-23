#include "Includes.h"

string intTostring(int x)
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

int stringToint(string str)
{
    int i;
    int nr=0;
    for(i=0;i<str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
            nr=nr*10+str[i]-'0';
        else throw string("Function stringToint expects number, not character \'")+str[i]+string("\'\n");
    }
    return nr;
}
