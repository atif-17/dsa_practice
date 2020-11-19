#include<iostream>
using namespace std;

string keys[10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void PhoneKeyPad(char *in, char *out, int i, int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //recursive case
    int digit=in[i]-'0';
    for(int k=0;keys[digit][k]!='\0';k++)
    {
        out[j]=keys[digit][k];
        PhoneKeyPad(in,out,i+1,j+1);
    }
}
int main(){
    char in[10];
    cin>>in;
    char out[10];
    PhoneKeyPad(in,out,0,0);
    return 0;
}
