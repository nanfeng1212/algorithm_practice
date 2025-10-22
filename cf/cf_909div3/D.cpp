#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
map<double,ll>mp;
const ll mod=1e9+7;
int x, p, m, i, result;
ll ksm(ll x,ll p,ll m)
{
	ll result= 1;
	while (p)
	{  if (p % 2 == 1)
			result = result*x%m;
		p /= 2;
		x = x*x%m;
	}
	return result;
}

int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a;

            double s = (double)a/ksm(2,a,mod);

            mp[s]++;
        }
        ll ans=0;
        for(auto it:mp)
            ans += it.second*(it.second-1)/2;
        cout<<ans<<endl;

    }
    return 0;
}
