#include<bits/stdc++.h>
using namespace std;
int t,k,n;
typedef long long ll;
ll a[200010];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=a[i-1];
        }
        ll ma=-1e18,ans=-1e18;
        for(int i=k;i<=n-k;i++)
        {
            ma=max(ma,a[i]-a[i-k]);
            ans=max(ans,ma+a[i+k]-a[i]);
        }
        cout<<ans<<endl;
    }
}