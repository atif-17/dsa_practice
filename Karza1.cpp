#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1, 4, 2, 7};
    int n = sizeof(arr)/sizeof(int);
    int k=3;
    int freq[k]={0};
    for(int i=0;i<n;i++){
        arr[i]=arr[i]%k;
        freq[arr[i]]++;
    }
    int ans=0;
    for(int i=0;i<=k/2;i++){
        if(i==0 || i==k-i){
            if(freq[i]>0) ans++;
        }
        else{
            ans+=max(freq[i],freq[k-i]);
        }
    }
    cout<<ans;
}
