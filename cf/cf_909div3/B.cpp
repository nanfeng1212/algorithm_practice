#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[150010];
int vis[150010];
vector<int>v;
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        memset(vis,0,sizeof vis);
        for(int j=1;j*j<=n;j++)
            if(n%j==0){
                    if(vis[j]==0&&j!=n){
                        v.push_back(j);
                        vis[j]=1;
                    }
                    if(vis[n/j]==0&&n/j!=n){
                        vis[n/j]=1;
                        v.push_back(n/j);
                    }
            }
        ll ans = 0;
        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            a[i]=a[i-1]+x;
        }
        int k = v.size();
        //cout<<k<<endl;
        for(int i=0;i<k;i++)
        {
            ll minn = 1e18;
            ll maxn = 0;
            for(int j=1;j+v[i]-1<=n;j+=v[i])
            {
                //cout<<j<<' '<<j+v[n][i]-1<<endl;
                maxn = max(maxn,abs(a[j+v[i]-1]-a[j-1]));
                minn = min(minn,abs(a[j+v[i]-1]-a[j-1]));
            }
            //cout<<maxn<<' '<<minn<<endl;
            ans = max(ans,abs(maxn-minn));
        }

        cout<<ans<<endl;
    }
    return 0;
}
