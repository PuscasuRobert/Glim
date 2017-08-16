#ifndef GLIM_SCREEN_H
#define GLIM_SCREEN_H

#include "glim/Tab.h"

#include "glim/Draw.h"

namespace glim {

class Screen
{
    public:
        glim::Draw drawEngine;
        vector<glim::Tab*>tab;

    private:
};

} // namespace glim

#endif // GLIM_SCREEN_H
