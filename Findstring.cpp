#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char words[][100]={
        "Hello",
        "World",
        "Coding",
        "Blocks"
    };
    char ch[100];
    cin.getline(ch,100);
    for(int i=0;i<4;i++)
    {
        int j=0;
        while(words[i][j]!='\0')
        {
            if(words[i][j]!=ch[j])
            {
                break;
            }
            j++;
        }
        if(words[i][j]=='\0')
        {
            cout<<"Yes";
        }
    }
}
