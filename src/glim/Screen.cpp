#include "glim/Screen.h"

namespace glim {

void Screen::createBuffer()
{
    tab.w=windowPtr->getSize().x;
    tab.h=windowPtr->getSize().y;
}

void Screen::addTab(glim::Tab* t)
{
    int i;

    for(i=0;i<t->son.size();i++)
    {
        ///...
        addTab(t->son[i]);
    }
}

Screen::~Screen()
{
    delete windowPtr;
};


} // namespace glim
