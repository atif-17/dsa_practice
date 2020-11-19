#include<iostream>
using namespace std;

int add(int m, int n)
{
    if(n==0)
        return 0;

    return m+add(m,n-1);
}
int main()
{
    cout<<add(4,5);
}
