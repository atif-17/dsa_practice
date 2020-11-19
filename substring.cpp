#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[]="atif";
    int n=4;
    for(int len=0;a[len]!='\0';len++)
    {
    for(int j=0;a[j]!='\0';j++)
    {
    for(int i=j;i<=len;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
    }
    }
}

