#include<iostream>
#include<string.h>
using namespace std;

int main() {
    int n;
    cin>>n; int max=-1;int len; string max_array;
    char ch[100];
    for(int i=0;i<=n;i++)
    {
        cin.getline(ch,100);
        len=strlen(ch);
        if(len>max)
        {
            max=len;
            max_array=ch;
        }
    }
    cout<<max_array;
}
