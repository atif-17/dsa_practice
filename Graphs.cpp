#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T,list<T> >adjList;
public:
    void addedge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir==true)
        {
            adjList[v].push_back(u);
        }
    }
    void BFS(T src)
    {

    }
    void Print()
    {
        for(auto node:adjList)
        {
            cout<<node.first<<"->";
            for(auto neighbours:adjList[node.first])
            {
                cout<<neighbours<<",";
            }
            cout<<endl;
        }
    }
} ;
int main()
{
    Graph<string> g;
    g.addedge("Putin","Trump");
    g.addedge("Putin","Modi");
    g.addedge("Modi","Trump");
    g.Print();
}
