#include<iostream>
using namespace std;
void PrintDecreasing(int *a, int n)
{
    if(n==0)
        return;
    PrintDecreasing(a+1,n-1);
    cout<<a[0];
    return;
}
void Print2(int *a, int n)
{
    if(n==0)
        return;

    cout<<a[n-1];
    Print2(a,n-1);
}
int main()
{
    int n=5;
    int a[]={1,2,6,4,5};
    PrintDecreasing(a,n);
    cout<<endl;
    Print2(a,n);
}
