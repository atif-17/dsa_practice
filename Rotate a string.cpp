#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char ch[100];
    cin.ignore();
    cin.getline(ch,100);
    int len=strlen(ch);
    int i=len-1;
    while(i>=0)
    {
        ch[i+n]=ch[i];
        i--;
    }
    i=0; int j=len;
    for(int k=1;k<=n;k++)
    {
        ch[i++]=ch[j++];
    }
    ch[len]='\0';
    cout<<ch;
}
