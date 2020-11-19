#include<iostream>
using namespace std;

int elephantways(int n, int m)
{
    //base case
    if(n==0 && m==0)
        return 1;
    //recursive case
    int x=0,y=0;
    for(int k=1;k<=n;k++)
    {
        x= x+elephantways(n-k,m);
    }
    for(int k=1;k<=m;k++)
    {
        y= y+elephantways(n,m-k);
    }
    return x+y;

}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<elephantways(n,m)<<endl;
}
