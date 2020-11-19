#include<iostream>
#include<string.h>
using namespace std;

void spiralprint( int rows, int columns, int a[][4])
{
    int sr=0, er=rows-1, sc=0, ec=columns-1;
    while(sr<=er && sc<=ec)
    {
        for(int i=sc;i<=ec;i++)
        {
            cout<<a[sr][i];
        }
        sr++;
        for(int i=sr;i<=er;i++)
        {
            cout<<a[i][ec];
        }
        ec--;
        if(sr<er){
        for(int i=ec;i>=sc;i--)
        {
            cout<<a[er][i];
        }
        er--;
        }
        if(sc<ec)
        {
        for(int i=er;i>=sr;i--)
        {
            cout<<a[i][sc];
        }
        sc++;
        }
    }
}
int main()
{
    int rows, columns;
    cin>>rows>>columns;
    int a[4][4];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>a[i][j];
        }
    }

    spiralprint(rows,columns,a);
    return 0;
}
