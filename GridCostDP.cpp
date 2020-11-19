#include<iostream>
using namespace std;

int MinCost(int cost[][4], int i, int j)
{
    if(i==0 && j==0)
    {
        return cost[i][j];
    }
    if(i==0 && j>0)
    {
        return cost[i][j]+MinCost(cost,i,j-1);
    }
    if(j==0 && i>0)
    {
        return cost[i][j]+MinCost(cost,i-1,j);
    }
    else
    {
        int op1= cost[i][j]+MinCost(cost,i-1,j);
        int op2= cost[i][j]+MinCost(cost,i,j-1);
        return min(op1,op2);
    }
}
int TopDown(int cost[][4], int i, int j, int dp[10][10])
{
    if(i==0 && j==0)
    {
        dp[i][j]=cost[i][j];
        return dp[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==0 && j>0)
    {
        dp[i][j]= cost[i][j]+TopDown(cost,i,j-1,dp);
        return dp[i][j];
    }
    if(j==0 && i>0)
    {
        dp[i][j]= cost[i][j]+TopDown(cost,i-1,j,dp);
        return dp[i][j];
    }
    else
    {
        int op1= cost[i][j]+TopDown(cost,i-1,j,dp);
        int op2= cost[i][j]+TopDown(cost,i,j-1,dp);
        dp[i][j]= min(op1,op2);
        return dp[i][j];
    }
}
int BottomUp(int cost[][4],int i,int j)
{
    int dp[10][10]={0};

    for(int k=0;k<=i;k++)
    {
        for(int l=0;l<=j;l++)
        {
            if(k==0 && l==0)
            {
                dp[k][l]=cost[k][l];
            }
            else if(k==0 && l>0)
            {
                dp[k][l]=cost[k][l]+dp[k][l-1];
            }
            else if(l==0 && k>0)
            {
                dp[k][l]=cost[k][l]+dp[k-1][l];
            }
            else
            {
                dp[k][l]=cost[k][l]+min(dp[k-1][l],dp[k][l-1]);
            }
        }
    }
    return dp[i][j];
}
int main()
{
    int cost[4][4]={
        {1,1,3,5},
        {10,1,1,8},
        {5,6,1,1},
        {3,1,1,1}
    };
    int dp[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            dp[i][j]=-1;
        }
    }
    int i,j;
    cin>>i>>j;
    cout<<TopDown(cost,i,j,dp)<<endl;
    cout<<BottomUp(cost,i,j)<<endl;
    cout<<MinCost(cost,i,j)<<endl;
}
