#ifndef GLIM_BUTTON_H
#define GLIM_BUTTON_H

#include "Includes.h"

namespace glim {

class Button
{
    public:
        int x,y,w,h;
        Button(vector<sf::Vector2i>p);

        sf::Texture background;
        vector<sf::Vector2i>points;
    private:

};

} // namespace glim

#endif // GLIM_BUTTON_H
