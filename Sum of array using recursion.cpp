#include<iostream>
using namespace std;

int sum(int *a, int n)
{
    if(n==0)
        return 0;

    return a[0]+sum(a+1,n-1);
}
int sum1(int *a, int n, int i)
{
    if(i==n)
        return 0;

    return a[i]+sum1(a,n,i+1);
}
int sum2(int *a, int n, int i)
{
    if(i==-1)
        return 0;

    return a[i]+sum2(a,n,i-1);
}
int main()
{
    int n=5;
    int a[]={1,2,6,4,5};
    cout<<sum(a,n)<<endl;
    cout<<sum1(a,n,0)<<endl;
    cout<<sum2(a,n,n-1)<<endl;

}
