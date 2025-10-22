#include <bits/stdc++.h>
using namespace std;
const int N=10100;
const int INF=0x3f3f3f3f;
vector <int> G[N];
int dp[N][3];//0表示该点覆盖 1表示该点儿子覆盖 2表示该点父亲覆盖
void dfs(int root,int pre)
{
    bool haveson=false;
    bool coverson=false;
    int inc=0x3f3f3f3f;
    for(int i=0;i<G[root].size();i++)
    {
        int to=G[root][i];
        if(to==pre) continue;
        haveson=true;
        dfs(to,root);
        dp[root][0]+=min(dp[to][0],min(dp[to][1],dp[to][2]));
        if(root==1) dp[root][2]=INF;
        else dp[root][2]+=min(dp[to][0],dp[to][1]);
        inc=min(inc,dp[to][0]-dp[to][1]);
        if(dp[to][0]<=dp[to][1])
        {
            coverson=true;
            dp[root][1]+=dp[to][0];
        }
        else
        {
            dp[root][1]+=dp[to][1];
        }
    }
    if(!haveson) dp[root][1]=INF;
    else if(!coverson) dp[root][1]+=1;
    dp[root][0]+=1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",min(dp[1][0],min(dp[1][1],dp[1][2])));
}