#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, q;
int main()
{
    cin >> q;
    while (q--) {
        cin >> n >> k;
        pair<ll, ll> p[100005];
        int cnt=0;
        for(int i=2; i<=n/i; i++)
        {
            int res = 0;
            while (n%i==0)
                res++,n/=i;
            p[++cnt] = {i,res};
        }
        if(n>1) p[++cnt]={n,1};
        ll ans = 1;
        for(int i=1; i<=cnt; i++)
        {
            if (p[i].second>=k) 
                ans *= pow(p[i].first, p[i].second);
        }
        cout << ans << endl;
    }
    return 0;
}