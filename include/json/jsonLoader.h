#ifndef JSON_JSONLOADER_H
#define JSON_JSONLOADER_H

#include "Includes.h"
//#include "glim/App.h"

namespace json {

class jsonLoader
{
    public:
        jsonLoader();
        jsonLoader(const char* path);
        ~jsonLoader();

        void load(const char* path  );
        jsonNode* J;

    private:
        void write(jsonNode *J,int level);
        void read(jsonNode* J);
        void nextCharacter();

        string clearSpaces();
        string getCharactersUntill(char character);
        string getCharactersUntill(const char* character);
        string getNumber();
        string sendError(string errorNumber,string chars);
        string sendError(string errorNumber,bool value);
        string sendError(string errorNumber,int value);

        ifstream* fin;
        char c;
        int output=0,line;

};
} // namespace json

#endif // JSON_JSONLOADER_H
