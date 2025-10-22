#include<bits/stdc++.h>
using namespace std;
int n,m,t;
typedef long long ll;
const int N=1e6+60;
ll f[N];
ll b[55];
struct ty{
    ll a,c;
    ll k;
}s[55];
bool cmp(ty x,ty y)
{
    return x.c*b[y.k]<y.c*b[x.k];
}
int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++)
        cin>>s[i].k>>s[i].a>>s[i].c;
    sort(s+1,s+1+m,cmp);
    memset(f,-50,sizeof(f));
    ll ans=-1e18;f[0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=t;j>=s[i].c;j--)
        {
            f[j]=max(f[j],f[j-s[i].c]+s[i].a-j*b[s[i].k]);
            ans=max(ans,f[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
    
}