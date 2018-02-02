#ifndef INCLUDES_H
#define INCLUDES_H

#include <GL/glew.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <string>
#include <deque>
#include <forward_list>
#include <functional>

#include <iostream>
#include <fstream>
#include <sstream>

#include <windows.h>
#include <stdio.h>
#include <dirent.h>

#include "Shader.h"

using namespace std;

class Shader;

extern sf::Event event;
extern Shader shader;

struct jsonNode
{
    string text;
    deque<deque<jsonNode> >son;
};

void setupOpenGL();
string intTostring(int x);
int stringToint(string str);

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
