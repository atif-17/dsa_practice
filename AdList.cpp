#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
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
        ll a,b; cin>>a>>b;
        if(a%b==0) cout<<0<<endl;
        else cout<<(a/b+1)*b-a<<endl;
    }
}
