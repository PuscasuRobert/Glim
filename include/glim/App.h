#ifndef GLIM_APP_H
#define GLIM_APP_H

#include "glim/Data.h"
#include "glim/Interface.h"

namespace glim {

class App
{
    public:
        glim::Data* dataTree;
        glim::Interface* interfaceTree;

        void run();
    private:
};

} // namespace glim

#endif // GLIM_APP_H
