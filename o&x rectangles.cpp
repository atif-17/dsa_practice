#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[n][n];
    int sr=0,er=n-1,sc=0,ec=n-1;
    char ch;
    while(sr<=er && sc<=ec)
    {
        if(sr%2==1)
            ch='O';
        else
            ch='X';
        for(int i=sc;i<=ec;i++)
        {
            a[sr][i]=ch;
        }
        sr++;
        for(int i=sr;i<=er;i++)
        {
            a[i][ec]=ch;
        }
        ec--;
        for(int i=ec;i>=sc;i--)
        {
            a[er][i]=ch;
        }
        er--;
        for(int i=er;i>=sr;i--)
        {
            a[i][sc]=ch;
        }
        sc++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
