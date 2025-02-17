#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int n,m;
    cin>>n>>m;
    int f[30010];
    for(int i=1;i<=m;i++)
    {
        int v,p;
        cin>>v>>p;
        for(int j=n;j>=v;j--)
            f[j]=max(f[j],f[j-v]+p*v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}