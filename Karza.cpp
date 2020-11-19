#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2, 5, 1, 4, 2, 3, 6, 5, 1};
    //vector<int> dp(9,0);
    int k;
    cin>>k;
    int temp=0;
    for(int i=0;i<k;i++){
        temp+=arr[i];
    }
    int mx=temp;
    for(int i=1;i<9-k;i++){
        mx=max(mx,temp+arr[i+k-1]-arr[i-1]);
        temp=temp+arr[i+k-1]-arr[i-1];
    }
    cout<<mx;
}
