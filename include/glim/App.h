#ifndef GLIM_APP_H
#define GLIM_APP_H

#include "glim/Draw.h"
#include "glim/Data.h"
#include "glim/Window.h"

namespace glim {

class App
{
    public:
        glim::Data data;
        vector<glim::Window*>window;

        void run();
    private:
};

} // namespace glim

#endif // GLIM_APP_H
