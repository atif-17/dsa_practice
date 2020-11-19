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

    void dfs_helper(T src, unordered_map<T,bool> &visited)
    {
        cout<<src<<" ";
        visited[src]=true;
        for(auto neighbour:adjList[src])
        {
            if(visited[neighbour]!=true)
            {
                dfs_helper(neighbour,visited);
            }
        }
        return;
    }

public:
    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir==true)
        {
            adjList[v].push_back(u);
        }
    }
    void BFS(T src)
    {
        queue<T> q;
        q.push(src);
        unordered_map<T,bool> visited;
        visited[src]=true;

        while(!q.empty())
        {
            T parent=q.front();
            q.pop();
            cout<<parent<<" ";
            for(auto child:adjList[parent])
            {
                if(visited[child]!=true)
                {
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
    }
    void Print()
    {
        for(auto node:adjList)
        {
            cout<<node.first<<"-->";
            //for(auto neighbours:node.second)
            for(auto neighbours:adjList[node.first])
            {
                cout<<neighbours<<",";
            }
            cout<<endl;
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

    void dfs(T src)
    {
        unordered_map<T,bool> visited;
        dfs_helper(src,visited);
        int component=1;

        for(auto i:adjList)
        {
            if(visited[i.first]!=true)
            {
                dfs_helper(i.first,visited);
                component++;
            }
        }
        cout<<component<<endl;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
	g.addEdge(2,1);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(30,15);
	g.addEdge(13,15);
	g.addEdge(33,13);
	g.addEdge(330,130);
	g.addEdge(331,131);
	g.dfs(0);

    //cout<<g.SSSP(0,5);

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
