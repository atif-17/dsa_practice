#include<iostream>
#include<math.h>
using namespace std;

void Permutations(char *in, int i)
{
    //base case
    if(in[i]=='\0')
    {
        cout<<in<<endl;
        return;
    }
    //recursive case
    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        Permutations(in,i+1);
        swap(in[i],in[j]);
    }
}
int main()
{
    char in[100];
    cin>>in;
    Permutations(in,0);
}
