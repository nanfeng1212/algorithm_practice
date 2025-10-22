#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a[1010];
int dp[1010];
int ans,ansnum;
void dfs(int i,int fa)
{
    
    dp[i]=1;
    int maxn=0;
    for(int j=0;j<a[i].size();j++)
    {
        if(a[i][j]==fa)continue;
        dfs(a[i][j],i);
        dp[i]+=dp[a[i][j]];
        maxn=max(maxn,dp[a[i][j]]);
    }
    maxn=max(maxn,n-dp[i]);
    if(ansnum>maxn)
    {
        ansnum=maxn;
        ans=i;
    }
    else if(ansnum==maxn)
    {
        if(ans>i)ans=i;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)dp[i]=0,a[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ans=0x3f3f3f3f;
        ansnum=0x3f3f3f3f;
        dfs(1,0);
        cout<<ans<<' '<<ansnum<<endl;
        return 0;
        }
}