#ifndef GLIM_WINDOW_H
#define GLIM_WINDOW_H

#include "glim/Screen.h"
#include "Includes.h"

namespace glim {

class Window
{
    public:
        sf::VideoMode videoMode;
        string title;
        sf::ContextSettings settings;

        sf::RenderWindow renderWindow;

        unsigned int priority;
        unsigned int currentScreen;
        deque<glim::Screen>screen;

        void create();

        void handleEvents();
        void render();
    private:
};

} // namespace glim

#endif // GLIM_WINDOW_H
