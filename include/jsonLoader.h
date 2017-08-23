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
        string getCharacters(char character,int nr=1);
        string getCharacters(const char* character,int nr=1);
        void write(jsonNode *J,int level);
        void read(jsonNode* J);

        ifstream fin;
        char c;
        jsonNode J;
    protected:

    private:
};

#endif // JSONLOADER_H
