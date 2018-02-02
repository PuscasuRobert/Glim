#ifndef GLIM_APP_H
#define GLIM_APP_H

#include "Includes.h"

namespace glim {

class App
{
    public:
        App(){};
        virtual ~App(){};
        void load(const char* path1,const char* path2);
        void createWidgetsTree(const char* path);
        void run();
};

class AppLoader
{
    public:
        AppLoader();
        void load(glim::App* app,const char* path1,const char* path2);

    private:
        struct Node;
        struct Link
        {
            Link()
            {
                int i;
                for(i=0;i<128;i++)
                    endNode[i]=0;
            }
            bool endNode[128];
            Node* state;
        };
        struct Node
        {
            int id;
            bool isFinal;
            char characterNode;
            Link link;
            function<void(char)>proccesing;
            Node(int _id)
            {
                id=_id;
                isFinal=0;
            }
        };
        vector<Node*>initialNodes;
        vector<Node*>nodes;
        forward_list<char> appStack;
        char opposite(char c);
        void addLink(Node* a,char c,Node* b);
};

} // namespace glim

#endif // GLIM_APP_H
