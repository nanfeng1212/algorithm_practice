#include<bits/stdc++.h>
using namespace std;
int n;
int h[6010];
bool fa[6010], son[6010];
vector<int>a[6010];
int f[6010][2];
int ans = -0x3f3f3f3f;
void dfs(int x)
{
    if(!fa[x])
    {
        f[x][0]=0;
        f[x][1]=h[x];
        ans=max(ans,max(f[x][0],f[x][1]));
        return ;
    }
    for(int i=0;i<a[x].size();i++)
    {
        int t = a[x][i];
        dfs(t);
        f[x][0] += max(f[t][0], f[t][1]);
        f[x][1] += f[t][0];
    }
    f[x][1] += h[x];
    ans = max(ans, max(f[x][1], f[x][0]));
}
int main()
{
    cin >> n;
    for(int i = 1; i <=n; i++)cin >> h[i];
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        fa[y]=1,son[x]=1;
        a[y].push_back(x);
    }
    for(int i=1; i <= n; i++)
    {
        if(!son[i]){
            dfs(i);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}