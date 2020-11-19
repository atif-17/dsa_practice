#include<iostream>
using namespace std;
int IsSorted(int *a,int n)
{
    //base case
    if(n==0 || n==1) //0 will only hit when the user inputs 0
        return true;
    //recursive case
    else if(a[0]<=a[1] && IsSorted(a+1, n-1))
        return true;
}
int main()
{
    int n=5;
    int a[]={1,2,6,4,5};
    if(IsSorted(a,n))
        cout<<"Sorted";
    else
        cout<<"Not Sorted";
}
