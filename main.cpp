#include "Includes.h"
#include "Shader.h"

#include "glim/App.h"
#include "glim/Button.h"
#include "glim/Draw.h"
#include "glim/HorizontalTab.h"
#include "glim/VerticalTab.h"
#include "glim/Screen.h"
#include "glim/Tab.h"
#include "glim/VerticalTab.h"
#include "glim/Window.h"
#include "glim/Interpreter.h"

#include "json/jsonLoader.h"

using namespace std;

void setupOpenGL();

sf::Event event;

glim::App app;
Shader shader;
json::jsonLoader JSON;
glim::Interpreter interpreter;
jsonNode js;

int main()
{
    /*
    app.window.resize(1);

    app.window[0]=new glim::Window;
    app.window[0]->priority=0;
    app.window[0]->currentScreen=0;

    app.window[0]->videoMode.width=800;
    app.window[0]->videoMode.height=600;
    app.window[0]->settings.depthBits = 24;
    app.window[0]->settings.stencilBits = 8;
    app.window[0]->settings.antialiasingLevel = 8;
    app.window[0]->settings.majorVersion = 3;
    app.window[0]->settings.minorVersion = 0;
    app.window[0]->title=string("MERGE");

    app.window[0]->create();

    app.window[0]->screen.resize(1);
    app.window[0]->currentScreen=0;
    app.window[0]->screen[0].tab=new glim::HorizontalTab;
    app.window[0]->screen[0].windowPtr=&app.window[0]->renderWindow;
    app.window[0]->screen[0].createBuffer();
    */

    try
    {
        JSON.load("interface.json");
        interpreter.setup(&app,JSON.J);
    }
    catch(string x)
    {
        cout<<x;
    }
    //shader.load("shaders/shader.vert","shaders/shader.frag");

    //app.run();

    /*vector<sf::Vector2i> p;
    p.push_back(sf::Vector2i(0,0));
    p.push_back(sf::Vector2i(250,0));
    p.push_back(sf::Vector2i(0,100));

    p.push_back(sf::Vector2i(0,100));
    p.push_back(sf::Vector2i(250,0));
    p.push_back(sf::Vector2i(250,100));

    glim::Button* b1=new glim::Button(p);
    drawEngine.addWidget(b1);
    drawEngine.createGPUdata();*/

    return 0;
}

void setupOpenGL()
{
    glewExperimental = GL_TRUE;
    glewInit();
}
