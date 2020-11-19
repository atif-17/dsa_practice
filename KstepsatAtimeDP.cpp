#include<iostream>
using namespace std;

int N_Stairs(int n, int k, int *dp)
{
    if(n==0)
    {
        dp[n]=1;
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans = ans + N_Stairs(n-i,k,dp);
    }
    dp[n]=ans;
    return ans;
}
int BottomUp(int n, int k=3)
{
    int* dp = new int[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                ans=ans+dp[i-j];
            }
        }
        dp[i]=ans;
    }
    return dp[n];
}
int BottomUpOptimised(int n, int k=3)
{
    int* dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(i-k-1>=0)
        {
            dp[i]=2*dp[i-1]-dp[i-k-1];
        }
        else
        {
            dp[i]=2*dp[i-1];
        }
    }
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    int* dp = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=-1;
    }
    cout<<N_Stairs(n,k,dp)<<endl;
    cout<<BottomUp(n)<<endl;
    cout<<BottomUpOptimised(n)<<endl;
}
