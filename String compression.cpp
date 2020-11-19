#include<iostream>
using namespace std;
int main() {
    char a[1000];
    cin.getline(a,1000);
    int i=0, count[256]={0}, check[256]={0};
    while(a[i]!='\0')
    {
        count[a[i]]++;
        i++;
    }
    i=0;
    while(a[i]!='\0')
    {
        if(check[a[i]]==0)
        {
        cout<<a[i];
        if(count[a[i]]>1)
        {
            cout<<count[a[i]];
        }
        check[a[i]]=1;
        }
        i++;
    }
	return 0;
}
