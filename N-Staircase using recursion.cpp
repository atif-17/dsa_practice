#include <iostream>
using namespace std;

int Nstaircase(int n, int k)
{
    //base case
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    //recursive case
    int sum=0;
    for(int j=1;j<=k;j++)
    {
        sum=sum+Nstaircase(n-j,k);
    }
    return sum;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<Nstaircase(n,k);
}
