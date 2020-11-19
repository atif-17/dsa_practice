#include<iostream>
using namespace std;

int BottomUp(int i, int j)
{
    int dp[10][10]={0};

    if(i==0 && j==0)
    {
        dp[i][j]=1;
    }
    int val=1;
    for(int k=1;k<=j;k++)
    {
        dp[0][k]=val;
        val*=2;
    }
    val=1;
    for(int k=1;k<=i;k++)
    {
        dp[k][0]=val;
        val*=2;
    }
    for(int k=1;k<=i;k++)
    {
        for(int l=1;l<=j;l++)
        {
            int sum=0;
            for(int x=0;x<k;x++)
            {
                sum+=dp[x][l];
            }
            for(int y=0;y<l;y++)
            {
                sum+=dp[k][y];
            }
            dp[k][l]=sum;
        }
    }
    for(int k=0;k<=i;k++)
    {
        for(int l=0;l<=j;l++)
        {
            cout<<dp[k][l]<<" ";
        }
        cout<<endl;
    }

    return dp[i][j];
}

int main()
{
    int i,j;
    cin>>i>>j;
    cout<<BottomUp(i,j);
}
