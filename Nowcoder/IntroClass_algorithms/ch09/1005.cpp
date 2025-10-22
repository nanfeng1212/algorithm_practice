#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ty{
    int x,y;
    long long w;
    bool operator<(const ty &a)const
    {
        return w>a.w;
    }
};
int vis[510][510];
long long g[510][510];
priority_queue<ty>q;
int rou[4][2]={-1,0,0,1,1,0,0,-1};
int main()
{
    int t;
    cin>>t>>n>>m;
    while(t--)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
                if(g[i][j]==0)g[i][j]=1e18;
                else if(g[i][j]==-1)g[i][j]=0;
                vis[i][j]=0;
            }
        for(int i=2;i<=m;i++)if(g[1][i]!=1e18)q.push({1,i,g[1][i]});
        for(int i=2;i<n;i++)if(g[i][m]!=1e18)q.push({i,m,g[i][m]});
        long long res=1e18;
        while(!q.empty())
        {
            ty temp=q.top();
            q.pop();
            if(temp.y==1||temp.x==n)
            {
                res=min(res,temp.w);
                continue;
            }
            if(vis[temp.x][temp.y])continue;
            vis[temp.x][temp.y]=1;
            for(int i=0;i<4;i++)
            {
                int dx=temp.x+rou[i][0];
                int dy=temp.y+rou[i][1];
                if(dx<1||dx>n||dy<1||dy>m||g[dx][dy]==1e18)continue;
                q.push({dx,dy,temp.w+g[dx][dy]});
            }
        }
        if(res==1e18)cout<<-1<<endl;
        else cout<<res<<endl;
    }
    return 0;
}