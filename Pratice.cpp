#include <bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    for(int t=1;t<=test;t++){
        string s;
        cin>>s;
        int ctr=0,flag=0;
        for(int i=0;i<s.length();i++){
            if(flag==0 && s[i]=='1'){
                flag=1;
            }
            else if(flag==1 && s[i]=='0'){
                ctr++;
            }
        }
        cout<<ctr<<endl;
    }
}
