#include "Includes.h"
#include "glim/App.h"

using namespace std;

sf::Event event;

glim::App app;

int main()
{
    setupOpenGL();
    app.load("GlimInterface.json","widgets/");
    app.run();

    return 0;
}
