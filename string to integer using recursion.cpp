#include<iostream>
#include<math.h>
using namespace std;

int StrToInt2(char *a, int n)
{
    //base case
    if(n==0)
    return 0;
    //recursive case
    int ans=ans*10+(a[0]-'0');
    return ans+StrToInt2(a,n-1);
}
int StrToInt(char *a, int n)
{
    //base case
    if(n==0)
    return 0;
    //recursive case
    int last_digit=a[n-1]-'0';
    return StrToInt(a,n-1)*10 + (a[n-1]-'0');
}
int main()
{
    char a[100];
    cin>>a;
    int n;
    cin>>n;
    cout<<StrToInt2(a,n);
}
