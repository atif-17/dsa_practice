#include<iostream>
#include<cstring>
using namespace std;

int LCS(char* a, char* b)
{
    int dp[10][10]={0};
    int m=strlen(a);
    int n=strlen(b);

    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][m];
}
int main()
{
    char a[]="ade";
    char b[]="cabde";

    cout<<LCS(a,b)<<endl;
}
