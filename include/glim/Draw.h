#ifndef GLIM_DRAW_H
#define GLIM_DRAW_H

#include "Includes.h"

#include "glim/Button.h"

namespace glim {

class Draw
{
    public:
        unsigned int VBO, VAO;
        int nrComponents=3;
        vector<GLfloat> vertices;

        deque<Button*>button;
        void createGPUdata();

        void clearBuffer();
        void addWidget(glim::Button* b);
        void run();

    private:
};

} // namespace glim

#endif // GLIM_DRAW_H
