#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010];
map<ll,int>mp;
int dp[100010];
int main(){
    //ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    ll x;
    cin >> n >> m >> x;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dp[i] = max(dp[i-1],mp[a[i]^x]);
        mp[a[i]] = i; 
    }
    while(m--){
        int l,r;
        cin >> l >> r;
        if(dp[r]>=l){
            cout << "yes" << endl;
        }
        else cout << "no" << endl;
    }
    return 0;
 
}