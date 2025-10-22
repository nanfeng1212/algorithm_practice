#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans=-0x3f3f3f3f;
ll dp[100010],v[100010];
vector<int>a[100010];
void dfs(int root,int fa)
{
    dp[root]=v[root];
    ans=max(ans,v[root]);
    for(int i=0;i<a[root].size();i++)
    {
        int son=a[root][i];
        if(son==fa)continue;
        dfs(son,root);
        ans=max(dp[root]+dp[son],ans);
        dp[root]=max(dp[root],v[root]+dp[son]);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}