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
    string name;

    fin.open(path);

    while(fin.get(c))
    {
        if(c=='{')
        {
            getCharacters('"');
            if(c=='"')
            {
                name=getCharacters('"');
                if(name=="app")
                {
                    getCharacters(':');

                }
            }
        }
    }
}

string jsonLoader::getCharacters(char character)
{
    int i;
    string str;

    while(fin.get(c))
    {
        if(c==character)
            return str;
        str+=c;
    }
}

