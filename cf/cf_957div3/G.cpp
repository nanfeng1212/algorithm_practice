#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
ll c[5005][5005]={0};
void init()
{
    for(int i=0;i<=5000;i++)
    {
        c[i][0]=1;
        c[i][i]=1;
        for(int j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=mod;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i=1;i<=n;i++)
    {
        for(int k2=0;k2<=n-i;k2++)
        {
            int k1=i-1-k2;
            if(k1%2||k1<0) continue;
            k1/=2;
            ans+=c[i-1][k1]*c[n-i][k2]%mod*i%mod;
            ans%=mod;
        }
    }
    for(ll i=n+1;i<=2*n+1;i++)
    {
        if(i%2==0) continue;
        ll j=(i-1)/2;
        ans+=c[n][j]%mod*i%mod;
        ans%=mod;

    }

    cout << ans << '\n';
}

int main()
{
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

