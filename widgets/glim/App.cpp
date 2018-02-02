#include "glim/App.h"

namespace glim {

void App::load(const char* path1,const char* path2)
{
    glim::AppLoader loader;
    loader.load(this,path1,path2);
    createWidgetsTree(path2);

}

void App::createWidgetsTree(const char* path)
{

}

void App::run()
{

}

AppLoader::AppLoader()
{
    int nrStates=500,i;
    nodes.resize(nrStates);
    for(i=0;i<nodes.size();i++)
        nodes[i]=new Node(i);

    int nrInitStates=2;
    initialNodes.resize(nrInitStates);
    initialNodes[0]=nodes[0];
    initialNodes[1]=nodes[1];

    addLink(0,'{',nodes[1]);
    addLink(0,'[',nodes[35]);

    addLink(nodes[1],'"',nodes[2]);
    addLink(nodes[2],ASCII,nodes[3]);

    ///......////


    ///optional: nodes[0]->isFinal=1;
}

void AppLoader::addLink(Node* a,char c,Node* b)
{
    if(a!=NULL)
    {
        a->link.endNode[c]=1;
        a->link.state=b;
    }
    b->characterNode=c;
}


void AppLoader::addLink(Node* a,char* c,Node* b)
{
    if(a!=NULL)
    {
        a->link.endNode[c]=1;
        a->link.state=b;
    }
    for(i=0;c[i]!=0;i++)
        b->characterNode=c[i];
}

void AppLoader::load(glim::App* app,const char* path1,const char* path2)
{
    int nr,i;
    char c;
    ifstream fin(path1);
    Node* currentNode;

    fin.get(c);
    appStack.push_front(opposite(c));

    nr=0;
    for(i=0;i<initialNodes.size();i++)
        if(initialNodes[i]->characterNode==1)
        {
            currentNode=initialNodes[i];
            nr++;
        }
    if(nr==0)
    {
        ///ERROR
    }
    else if(nr>1)
    {
        ///ERROR
    }

    while(!(currentNode->isFinal!=1 && appStack.empty()==0))
    {
        fin.get(c);
        if(currentNode->characterNode==c)
        {
            currentNode=currentNode->link.state;
            currentNode->proccesing(c);
        }
    }
}

char AppLoader::opposite(char c)
{
    if(c=='{')
        return '}';
    if(c=='[')
        return ']';
    if(c=='"')
        return '"';
}

} // namespace glim
