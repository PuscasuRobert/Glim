#include "glim/Window.h"

namespace glim {

void Window::create()
{
    renderWindow->create(videoMode, title, sf::Style::Close, settings);

    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, videoMode.width, videoMode.height);
    glEnable(GL_DEPTH_TEST);

}

void Window::render()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    shader.use();
    screen[currentScreen].drawEngine.run();

    renderWindow->display();
}

void Window::handleEvents()
{
    while (renderWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            renderWindow->close();
    }
}

} // namespace glim
