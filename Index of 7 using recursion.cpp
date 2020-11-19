#include<iostream>
using namespace std;

int b[100];
void FindAllIndices(int *a, int n,int i,int j)
{
    if(i==n)
        return;

    if(a[i]==7)
    {
        b[j++]=i;
    }
    FindAllIndices(a,n,i+1,j);
    return;
}
int CheckLastIndex(int *a,int n,int i,int index)
{
    if(i==n)
        return index;

    if(a[i]==7)
        index=i;

    CheckLastIndex(a,n,i+1,index);
}
int CheckLastIndex2(int *a,int n,int i,int ChotaIndex)
{
    if(i==n)
    {
        if(ChotaIndex==0)
            return -1;
        else
            return ChotaIndex;
    }

    if(a[i]==7)
    {
        ChotaIndex=i;
    }

    return CheckLastIndex2(a,n,i+1,ChotaIndex);
}
int CheckFirstIndex(int *a,int n,int i)
{
    if(i==n)
        return -1;
    else if(a[i]==7)
        return i;
    return CheckFirstIndex(a,n,i+1);
}
bool Check7(int *a,int n)
{
    if(n==0)
        return false;
    else if(a[0]==7)
        return true;
    return Check7(a+1,n-1);
}
int main()
{
    int a[]={1,2,7,3,6,7,7,9,10};
    int n=sizeof(a)/sizeof(int);
    if(Check7(a,n))
        cout<<"7 present"<<endl;
    else
        cout<<"7 not present"<<endl;

    if(CheckFirstIndex(a,n,0)!=-1)
        cout<<"First index: "<<CheckFirstIndex(a,n,0)<<endl;
    else
        cout<<"7 not found"<<endl;

    if(CheckLastIndex(a,n,0,-1)!=-1)
        cout<<"Last index: "<<CheckLastIndex(a,n,0,-1)<<endl;
    else
        cout<<"7 not found"<<endl;

    FindAllIndices(a,n,0,0);
}
