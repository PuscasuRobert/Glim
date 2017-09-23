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

/*
    int i,j;
    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(J->son[i][j].text=="")
            {

            }
            else if(J->son[i][j].text=="")
            {

            }
            else
                throw string("Error: property not found 1");
        }
*/

void Interpreter::setup(glim::App* app,jsonNode* J)
{
    int i,j;
    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(J->son[i][j].text=="interfaceTree")
                setupInterface(&app->interfaceTree,&J->son[i][j]);
            else if(J->son[i][j].text=="dataTree")
            {

            }
            else
                throw string("Error: property not found 1");
        }
}

void Interpreter::setupInterface(glim::Interface* interfaceTree,jsonNode* J)
{
    int i,j;
    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(J->son[i][j].text=="window")
            {
                interfaceTree->window.push_back(glim::Window());
                setupWindowVector(interfaceTree->window,&J->son[i][j]);
            }
            else
                throw string("Error: property not found 2");
        }
}

void Interpreter::setupWindowVector(deque<glim::Window>& windowVector,jsonNode* J)
{
    int i,j;
    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(J->son[i][j].text=="")
            {
                windowVector.push_back(glim::Window());
                setupWindow(&windowVector[j],&J->son[i][j]);
            }
            else
                throw string("Error: property not found 3");
        }
}

void Interpreter::setupWindow(glim::Window* window,jsonNode* J)
{
    int i,j;
    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(J->son[i][j].text=="priority")
                window->priority=stringToint(J->son[i][j].son[0][0].text);
            else if(J->son[i][j].text=="currentScreen")
                window->currentScreen=stringToint(J->son[i][j].son[0][0].text);
            else if(J->son[i][j].text=="VideoMode")
                setupVideoMode(&window->videoMode,&J->son[i][j]);
            else if(J->son[i][j].text=="title")
            {

            }
            else if(J->son[i][j].text=="screens")
            {

            }
            else
                throw string("Error: property not found 4");
        }
}

void Interpreter::setupVideoMode(sf::VideoMode* videoMode,jsonNode* J)
{
    int i,j;
    for(i=0;i<J->son.size();i++)
        for(j=0;j<J->son[i].size();j++)
        {
            if(J->son[i][j].text=="width")
                videoMode->width=stringToint(J->son[i][j].son[0][0].text);
            else if(J->son[i][j].text=="height")
                videoMode->height=stringToint(J->son[i][j].son[0][0].text);
            else if(J->son[i][j].text=="settings")
            {

            }
            else
                throw string("Error: property not found 5");
        }
}

} // namespace glim
