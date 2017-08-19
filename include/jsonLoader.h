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

        string getCharacters(char character);

        ifstream fin;
        char c;

    protected:

    private:
};

#endif // JSONLOADER_H
