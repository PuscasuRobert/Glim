#ifndef JSONLOADER_H
#define JSONLOADER_H

#include "Includes.h"
#include "glim/App.h"

class jsonLoader
{
    public:
        jsonLoader();
        jsonLoader(const char* path);

        void load(const char* path  );
        string clearSpaces();
        string getCharactersUntill(char character,int nr=1);
        string getCharactersUntill(const char* character,int nr=1);
        string getCharactersWhile(const char* characters);
        void write(jsonNode *J,int level);
        void read(jsonNode* J);

        ifstream fin;
        char c;
        jsonNode J;
        int output=2;
    protected:

    private:
};

#endif // JSONLOADER_H
