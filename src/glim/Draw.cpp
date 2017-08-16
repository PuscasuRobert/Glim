#include "glim/Draw.h"

namespace glim {

void Draw::createGPUdata()
    {
        /*glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertices.size(), &vertices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        */
    }


    void Draw::run()
    {
        /*glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size()/nrComponents);
        glBindVertexArray(0);
        */
    }


    /*void Draw::addWidget(glim::Button* b)
    {
        int i;
        for(i=0;i<b->points.size();i++)
        {
            //Positions
            vertices.push_back((b->points[i].x-window.getSize().x/2.0)/window.getSize().x*2.0);
            vertices.push_back(-(b->points[i].y-window.getSize().y/2.0)/window.getSize().y*2.0);
            vertices.push_back(0.0f);
        }
    }*/

    void Draw::clearBuffer()
    {
        vertices.clear();
    }

} // namespace glim
