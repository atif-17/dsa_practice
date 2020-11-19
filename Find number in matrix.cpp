#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int rows, columns;
    cin>>rows>>columns;
    int a[rows][columns];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>a[i][j];
        }
    }
    int key;
    cin>>key;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(a[i][j]==key)
            {
                cout<<i<<' '<<j<<endl;
                break;
            }
        }
    }
}
