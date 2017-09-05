#ifndef INCLUDES_H
#define INCLUDES_H

#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <vector>
#include <string>
#include <deque>

#include <iostream>
#include <fstream>
#include <sstream>

#include <windows.h>

#include "Shader.h"

using namespace std;

class Shader;

extern sf::Event event;
extern Shader shader;

struct jsonNode
{
    string text;
    deque<deque<jsonNode>>son;
};

/*
namespace glim
{
    class App;
    class Window;
    class Screen;
    class Tab;
    class HorizontalTab;
    class VerticalTab;

    class Data;
    class Draw;

    class Button;
}*/

#endif // INCLUDES_H
