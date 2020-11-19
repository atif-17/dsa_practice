#include<iostream>
#include<string.h>
using namespace std;
void swap(char *s1, char *s2)
{
    char temp[100];
    int i=0;
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
}
int main()
{
    int n,j;
    cin>>n;
    cin.ignore();
    char a[n][100];
    for(int i=0;i<n;i++)
    {
        cin.getline(a[i],100);
    }
    for(int k=0;k<=n-2;k++)
    {
    for(int i=0;i<=n-2-k;i++)
    {
        for(int j=0;a[i][j]!='\0';j++) //a[i][j]!='\0' because it satisfies both cases when a[i] is bigger or smaller than a[i+1]
        {
        if(a[i+1][j]<a[i][j])
        {
            swap(a[i],a[i+1]);
            break;
        }
        else if(a[i+1][j]>a[i][j])
        {
            break;
        }
        }
    }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;a[i][j]!='\0';j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
