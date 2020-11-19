#include<iostream>
#include<math.h>
using namespace std;

void Merge(int *a, int *x, int *y, int s, int e)
{
    int mid=(s+e)/2;
    int i=s, j=mid+1, k=s;
    while(i<=mid && j<=e)
    {
        if(x[i]<y[j])
        {
            a[k++]=x[i++];
        }
        else
        {
            a[k++]=y[j++];
        }
    }
    while(i<=mid)
    {
        a[k++]=x[i++];
    }
    while(j<=e)
    {
        a[k++]=y[j++];
    }
}
void MergeSort(int *a, int s, int e)
{
    //base case
    if(s>=e) //only s==e required
        return;
    //Divide
    int mid=(s+e)/2, x[100], y[100];
    for(int i=0;i<=mid;i++)
        x[i]=a[i];
    for(int i=mid;i<=e;i++)
        y[i]=a[i];
    //Sort
    MergeSort(x,s,mid);
    MergeSort(y,mid+1,e);
    //Merge
    Merge(a,x,y,s,e);
}
int main()
{
    int a[]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(int);
    MergeSort(a,0,n-1);\
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
}
