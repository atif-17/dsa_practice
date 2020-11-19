#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(1);
    //cout<<v.capacity()<<endl;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    //cout<<v.capacity()<<endl;
    v.push_back(5);
    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';
    v.pop_back();v.push_back(7);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';

    if(!v.empty())
        cout<<"no";

}
