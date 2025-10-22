#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000009;

ll a[10000005];
ll qsm(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
int main(){
    int m,k;
    cin >> m >> k;
    a[0] = 1;
    for(int i=1;i<=m;i++){
        a[i] = (a[i-1]+m-1)%mod;
    }
    ll cur = 0;
    ll ans = 0;
    for(int i=1;i<=k;i++){
        ans = (ans+(cur+1)*m%mod)%mod;
        cur = (cur*(a[i-1]-1)%mod+(cur+1)*m%mod)%mod;
        cur = cur*qsm(a[i]*a[i-1],mod-2)%mod;
    }
    cout << ans << endl;
    return 0;
}