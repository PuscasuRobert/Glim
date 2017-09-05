#include "glim/Interpreter.h"

namespace glim {

Interpreter::Interpreter()
{
    //ctor
}

Interpreter::~Interpreter()
{
    //dtor
}

string Interpreter::findProperty(jsonNode* J,int i,int j)
{
    /*if(J->son[i][j].text.size()==0)
        return J->text;
    return J->son[i][j].text;*/
}

void Interpreter::setup(glim::App* app,jsonNode* J)
{
    int i,j;

    /*for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(findProperty(J,i,j)=="interface")
            {
                app->interfaceTree=new glim::Interface;
                setupInterface(app->interfaceTree,&J->son[i][j]);
            }
        }*/
}

void Interpreter::setupInterface(glim::Interface* interfaceTree,jsonNode* J)
{
    int i,j;

    /*for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(findProperty(J,i,j)=="window")
            {
                interfaceTree=new glim::Interface;
                setupWindowVector(&interfaceTree->window,&J->son[i][j]);
            }
        }*/

}

void Interpreter::setupWindowVector(deque<glim::Window>* window,jsonNode* J)
{

}

void Interpreter::setupWindow(glim::Window* window,jsonNode* J)
{
    int i,j;

}

} // namespace glim
