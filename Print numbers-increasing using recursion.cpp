#include<iostream>
using namespace std;
void PrintIncreasing(int *a,int n)
{
    if(n==0)
        return;

    cout<<a[0];
    PrintIncreasing(a+1,n-1);
    return;
}
int main()
{
    int n=5;
    int a[]={1,2,6,4,5};
    PrintIncreasing(a,n);
}
