#ifndef GLIM_TAB_H
#define GLIM_TAB_H

#include "Includes.h"

namespace glim {

class Tab
{
    public:
        deque<glim::Tab>son;
        Tab();
        virtual ~Tab();

    protected:

    private:
};

} // namespace glim

#endif // GLIM_TAB_H
