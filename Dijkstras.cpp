#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T,list<pair<T,int> > >h;
public:
    void addEdge(T u,T v,int dist,bool bidir=true)
    {
        h[u].push_back(make_pair(v,dist));
        if(bidir==true)
        {
            h[v].push_back(make_pair(u,dist));
        }
    }
    void Print()
    {
        for(auto node:h)    //for each node belonging to h
        {
            cout<<node.first<<"-->";
            for(auto neighbour:node.second)
            {
                cout<<"("<<neighbour.first<<","<<neighbour.second<<")"; //first and second works on hash maps and pairs
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("Mumbai","Delhi",1);
    g.addEdge("Punr","Delhi",1);
    g.addEdge("Mumbai","Pune",1);
    g.Print();
}
