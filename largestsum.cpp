#include<iostream>
#include<string.h>
using namespace std;

int largestsum(int a[][4], int rows, int columns)
{
    int max1=-1, sum=0, sum1=0, maxx,j;
    for(int i=0;i<rows;i++)
    {
        sum=0;
        for( j=0;j<columns;j++)
        {
            sum+=a[i][j];
        }
        if(sum>max1)
        {
            max1=sum;
            maxx=i;
        }
    }
    for(int i=0;i<columns;i++)
    {
        sum1=0;
        for( j=0;j<rows;j++)
        {
            sum1+=a[j][i];
        }
        if(sum1>max1)
        {
            max1=sum1;
            maxx=i;
        }
    }
    return maxx;
}
int main()
{
    int rows, columns;
    cin>>rows>>columns;
    int a[4][4]={{1,5,2,200},{3,3,6,7},{2,2,5,1},{8,90,1,1}};
//    for(int i=0;i<rows;i++)
//    {
//        for(int j=0;j<columns;j++)
//        {
//            cin>>a[i][j];
//        }
//    }

    cout<<largestsum(a,rows, columns);
    return 0;
}
