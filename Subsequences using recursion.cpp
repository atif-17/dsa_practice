/*#include<iostream>
using namespace std;

void Subsequences(char *in, int i, char *out, int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //recursive case
    //ek baar consider mat karo
    Subsequences(in,i+1,out,j);
    //ek baari kar lo
    out[j]=in[i];
    Subsequences(in,i+1,out,j+1);
}
int main()
{
    char in[100];
    cin>>in;
    char out[100];
    Subsequences(in,0,out,0);
}*/
#include<iostream>
using namespace std;

int CountSubsequences(string in, string out, int i, int j)
{
    //base case
    if(in[i]=='\0')
    {
        return 1;
    }

    //ek baar include nahi karke
    int x=CountSubsequences(in,out,i+1,j);
    //ek baar include karke
    out[j]=in[i];
    int y=CountSubsequences(in,out,i+1,j+1);
    return x+y;
}
void subsequences(string in, string out)
{
    //base case
    if(in.size()==0)
    {
        cout<<out<<' ';
        return;
    }

     subsequences(in.substr(1),out);
     subsequences(in.substr(1),out+in[0]);
     return;

}
int main() {
    string a;
    cin>>a;
    string b=a;
    subsequences(a," ");
    //cout<<endl<<CountSubsequences(a,b,0,0);
	return 0;
}
