#include<iostream>
#include<string.h>
using namespace std;
int main() {
    char a[1000];
    cin.getline(a,1000);
    int i=0, j=strlen(a)-1;
    while(i<j)
    {
        //cout<<i<<' '<<j;
        if(a[i]!=a[j])
        {
            cout<<"false";
            break;
        }
        i++;j--;
    }
    if(i>=j)
    cout<<"true";
	return 0;
}
