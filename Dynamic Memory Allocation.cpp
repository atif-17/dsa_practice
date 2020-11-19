#include<iostream>
using namespace std;

int* CreateArray(int n)
{
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    arr[2]=3;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    int *a=new int;
    *a=10;cout<<*a;
}
