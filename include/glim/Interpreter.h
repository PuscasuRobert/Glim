#ifndef GLIM_INTERPRETER_H
#define GLIM_INTERPRETER_H

#include "Includes.h"
#include "glim/App.h"

namespace glim {

class Interpreter
{
    public:
        Interpreter();
        virtual ~Interpreter();

        void setup(glim::App* app,jsonNode* J);
        void setupInterface(glim::Interface* interfaceTree,jsonNode* J);
        void setupWindowVector(deque<glim::Window>* interfaceTree,jsonNode* J);
        void setupWindow(glim::Window* window,jsonNode* J);
        string findProperty(jsonNode* J,int i,int j);

    protected:

    private:
};

} // namespace glim

#endif // GLIM_INTERPRETER_H
