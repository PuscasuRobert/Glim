#include "glim/App.h"

namespace glim {

void App::run()
{
    int running=true;
    int i;

    while(running==true)
    {
        running=false;
        for(i=0;i<window.size();i++)
            if(window[i]->priority==0)
                if(window[i]->renderWindow.isOpen())
                    running=true;
        if(running==false)
            break;
        for(i=0;i<window.size();i++)
        {
            window[i]->handleEvents();
            window[i]->render();
        }
    }
}


} // namespace glim
