#include<iostream>
using namespace std;
int main()
{
    int n,i,temp,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=n-2;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
        cout>>a[i];
}
