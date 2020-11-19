#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T> > adjList;
public:
    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir==true)
        {
            adjList[v].push_back(u);
        }
    }
    int SSSP(T src, T des)
    {
        unordered_map<T,T> parent_map;
        queue<T> q;
        q.push(src);
        unordered_map<T,int> dist;  //dist from source
        for(auto i:adjList)
        {
            dist[i.first]=INT_MAX;
        }
        dist[src]=0;    //distance of source from source is 0
        parent_map[src]=src;

        while(!q.empty())
        {
            T parent=q.front();
            q.pop();
            for(auto child:adjList[parent])
            {
                if(dist[child]==INT_MAX)
                {
                    dist[child]=1+dist[parent];
                    q.push(child);
                    parent_map[child]=parent;
                }
            }
        }
        T temp=des;
        while(temp!=src)
        {
            cout<<temp<<"<--";
            temp=parent_map[temp];
        }
        cout<<src<<endl;
        for(auto i:dist)
        {
            cout<<"Distance of "<<i.first<<" from "<<src<<" is "<<i.second<<endl;
        }

        return dist[des];
    }
};

int main()
{
    Graph<int> g;

    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;

    int u,v;
    for(u=0;u<=36;u++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            v=u+dice+board[u+dice];
            g.addEdge(u,v,false);
        }
    }

    cout<<"Shortest distance is "<<g.SSSP(0,36);

//    g.addEdge("Putin","Trump",false);
//    g.addEdge("Putin","Modi",false);
//    g.addEdge("Trump","Modi",true);
//    g.addEdge("Yogi","Modi",true);
//    g.addEdge("Yogi","Prabhu",false);
//    g.addEdge("Prabhu","Modi",false);
//    g.addEdge("Putin","Pope",false);

    //g.BFS("Putin");
    //g.Print();
}

