#include "Includes.h"
#include "Shader.h"

#include "glim/App.h"
#include "glim/Button.h"
//#include "glim/Data.h"
#include "glim/Draw.h"
#include "glim/HorizontalTab.h"
#include "glim/VerticalTab.h"
#include "glim/Screen.h"
#include "glim/Tab.h"
#include "glim/VerticalTab.h"
#include "glim/Window.h"

#include "jsonLoader.h"

using namespace std;

void setupWindow();

sf::Event event;

glim::App app;
Shader shader;
jsonLoader json;
jsonNode js;


float lungime[1000]={694,694,600.5,564,564,564,694,694,800.5,764,764,764,694,694,800.5,764,764,694,694,400.5,364,364,301,500,301,500,301,301,500,301,500,301,301,764,764,720,720,764,712.5,720,720,364,364,364};
float latime [100]={510,510,  510,100,100,497,510,510,  510,100,100,497,510,510,  510,100,100,510,510,510  ,100,100,105,105,105,105,464,105,105,105,105,464,105,310,297,310,310,310,789.5,310,310,310,310,297};


int main()
{
    int i,j;


    int n;
    float total=0;

    for(i=0;i<44;i++)
        for(j=0;j<44;j++)
            total+=lungime[i]*latime[j];
    cout<<total;

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


    //json.load("interface.json");

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

void setupWindow()
{
    glewExperimental = GL_TRUE;
    glewInit();
}
