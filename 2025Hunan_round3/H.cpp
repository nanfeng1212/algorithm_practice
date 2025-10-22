#include<bits/stdc++.h>
#define int long long
#define ll long long
const int mod = 998244353;
using namespace std;

ll ksm(ll a,ll b){
    ll ans = 1;
    while (b){
        if (b&1) ans = ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}


void solve(){
    int n;
    cin >> n;
    string s1="",s2="";
    vector<int>v1(n+1),v2(n+1);
    vector<int>ans1(n+1),ans2(n+1);

    for (int i=1; i<=n; i++)cin>>v1[i];
    for (int i=1; i<=n; i++)cin>>v2[i];

    ans1[n] = v1[n]-1;
    ans2[n] = v2[n]-1;
    s1 = s1+char(ans1[n]+'0');
    s2 = s2+char(ans2[n]+'0');
    int cnt1 = 0,cnt2 = 0;
    for (int i=n-1;i>=1;i--) {
        if(ans1[i+1]==1) ++cnt1;
        if(cnt1%2) ans1[i] = 3-v1[i];
        else ans1[i] = v1[i]-1;
        if(ans2[i+1]==1) ++cnt2;
        if(cnt2%2) ans2[i] = 3-v2[i];
        else ans2[i] = v2[i]-1;
        s1 = s1+char('0'+ans1[i]);
        s2 = s2+char('0'+ans2[i]);
    }
    int sum1 = 0,sum2=0;
    int c=1;
    int i=1;
    while(i <= n){
        sum1 = (sum1+c*ans1[i]%mod)%mod;
        sum2 = (sum2+c*ans2[i]%mod)%mod;
        c = c*3%mod;
        i++;
    }
    if (s1>=s2)
        cout << (sum1-sum2+mod)%mod << '\n';
    else
        cout << (sum2-sum1+mod)%mod << '\n';
}

signed main() {
    cout << fixed << setprecision(12);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}