#include<iostream>
#include<math.h>
using namespace std;

void bubblesort2(int *a, int n, int i, int k)
{
    //main base case
    if(i==n-1)
        return;
    //subordinate base case
    else if(k==n-1)
        bubblesort2(a,n,i+1,0);
    //recursive case
    else{
    if(a[k+1]<a[k])
    {
        swap(a[k],a[k+1]);
    }
    bubblesort2(a,n,i,k+1);
    }
}
void bubblesort(int *a, int n, int i)
{
    //Main base case
    if(n==1)
        return;
    //Subordinate base case
    if(i==n-1)
    {
        i=0;
        n--;
    }

    //Recursion case
    if(a[i]>a[i+1])
    {
        swap(a[i],a[i+1]);
    }
    bubblesort(a,n,i+1);
}
int main()
{
    int a[5]={61,82,34,45,5};
    int n=sizeof(a)/sizeof(int);
    //bubblesort(a,n,0);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    bubblesort2(a,n,0,0);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
