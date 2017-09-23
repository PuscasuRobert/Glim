#ifndef GLIM_SCREEN_H
#define GLIM_SCREEN_H

#include "Includes.h"

#include "glim/Draw.h"
#include "glim/Tab.h"

namespace glim {

class Screen
{
    public:
        ~Screen();
        glim::Draw drawEngine;
        glim::Tab tab;

        sf::RenderWindow* windowPtr;

        void createBuffer();
        void addTab(glim::Tab* t);
    private:
};

} // namespace glim

#endif // GLIM_SCREEN_H
