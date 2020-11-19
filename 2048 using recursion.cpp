#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<list>
#define loop(i,a,n) for (int i=a;i<n;i++)
#define loopRev(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll mod=1000000007;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    ios
    int test; cin>>test;
    while(test--){
        ll n,diff;cin>>n; vector<ll> a(n); vector<ll> b(n); loop(i,0,n)cin>>a[i]; loop(i,0,n)cin>>b[i];
        int g=0; unordered_map<ll,bool> m;
        loop(i,0,n){
            if(a[i]!=b[i]){
                diff = b[i]-a[i];
                int f=0;
                for(auto j:m){
                    if(diff%j.first==0){
                        f=1; break;
                    }
                }
                if(f==0){cout<<i<<" ";
                    g=1;
                    break;
                }
                m[a[i]]=true;
            }
        }
        if(g==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
