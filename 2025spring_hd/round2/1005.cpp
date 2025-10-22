#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t = 1;
    cin >> t;
    while (t--){
        ll n,k;
        cin >> n >> k;
        if(k%2){
            cout<<0<<'\n';
            continue;
        }
        ll m = 2*n/k;
        if(m%2==0)
            m--;
        ll t = (m+1)/2;
        ll ans = t*n-k*t*t/2;
        cout<<ans<<'\n';
    }
}