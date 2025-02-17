#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int>a[110];
typedef long long ll;
int  v[110][110];
int dp[110][110];
int ans=-0x3f3f3f3f;
void dfs(int x,int fa)
{
    dp[x][0]=0;
   // ans=max(ans,dp[1][0]);
    for(int i=0;i<a[x].size();i++)
    {
        int son=a[x][i];
        if(son==fa)continue;
        dfs(son,x);
        for(int k=q;k>=0;k--)
            for(int j=0;j<k;j++)
                dp[x][k]=max(dp[x][k],dp[x][j]+dp[son][k-j-1]+v[x][son]);
    }
}
int main()
{
    cin>>n>>q;
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    for(int i=1;i<n;i++)
    {
        int x,y;
        int w;
        cin>>x>>y>>w;
        a[x].push_back(y);
        a[y].push_back(x);
        v[x][y]=v[y][x]=w;
    }
    dfs(1,0);
    cout<<dp[1][q];
    return 0;
}