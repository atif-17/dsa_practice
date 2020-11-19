#include<iostream>
#include<math.h>
using namespace std;

int binarysearch(int *a, int s, int e, int key)
{
    //base case
    if(s>e)
        return -1;
    //recursive case
    int mid=(s+e)/2;
    if(a[mid]==key)
        return mid;
    else if(a[mid]<key)
        binarysearch(a,mid+1,e,key);
    else
        binarysearch(a,s,mid-1,key);

}
int main()
{
    int a[]={1,9,9,10,35,344};
    int n=sizeof(a)/sizeof(int);
    int key=344,s=0,e=n-1;
    cout<<"Index of key: "<<binarysearch(a,s,e,key);
}
