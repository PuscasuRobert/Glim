#ifndef GLIM_INTERFACE_H
#define GLIM_INTERFACE_H

#include "glim/Window.h"

namespace glim {

class Interface
{
    public:
        Interface();
        virtual ~Interface();

        deque<glim::Window>window;

    protected:

    private:
};

} // namespace glim

#endif // GLIM_INTERFACE_H
