#include<iostream>
#include<unordered_map>
#include<set>
#include<list>
#include<climits>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T,list<pair<T,int> > > m;
public:
    void addEdge(T u, T v, int dist, bool bidir=true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir==true)
        {
            m[v].push_back(make_pair(u,dist));
        }
    }
    void Print()
    {
        for(auto i:m)
        {
            cout<<i.first<<"-->";
            for(auto j:m[i.first])  //or i.second
            {
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }
    void Dijkshtras(T src, T destination)
    {
        unordered_map<T,T> parent_map;
        parent_map[src]=src;
        unordered_map<T,int> dist;
        for(auto i:m)
        {
            dist[i.first]=INT_MAX;
        }
        dist[src]=0;
        set<pair<int,T> > s;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            auto P=*(s.begin());    //pair of node and dist
            T node=P.second;
            int nodeDist=P.first;
            s.erase(s.begin()); //minimum dist at front

            for(auto neighbour:m[node])
            {
                if(nodeDist+neighbour.second < dist[neighbour.first])
                {
                    T des=neighbour.first;
                    auto f=s.find(make_pair(dist[des],des));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    dist[des]=nodeDist+neighbour.second;
                    s.insert(make_pair(dist[des],des));
                    parent_map[des]=node;
                }
            }
        }
        for(auto i:m)
        {
            cout<<"Distance of "<<i.first<<" from "<<src<<" is "<<dist[i.first]<<endl;
        }
        cout<<endl<<"Path from source to destination"<<endl;
        while(destination!=src)
        {
            cout<<destination<<"<--";
            destination=parent_map[destination];
        }
        cout<<src<<endl;
    }
};
int main()
{
    Graph<string> g;

    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Amritsar","Delhi",1);
    g.addEdge("Delhi","Jaipur",2);
    g.addEdge("Mumbai","Jaipur",8);
    g.addEdge("Delhi","Agra",1);
    g.addEdge("Mumbai","Bhopal",3);
    g.addEdge("Bhopal","Agra",2);

    g.Print();
    cout<<endl;
    g.Dijkshtras("Amritsar","Bhopal");
}
