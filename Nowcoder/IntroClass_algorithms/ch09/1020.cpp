#include<bits/stdc++.h>
using namespace std;
int n;
char g[110][110];
int vis[110][110];
int dx[4] = {1, -1, 0, 0},dy[4] = {0, 0, -1, 1};
struct ty
{
    int x, y;
    int prex, prey;
    int dis; // 转弯次数
    bool operator<(const ty &w) const  // 优先队列中按照转弯次数从小到大排列
    {
        return dis > w.dis;
    }
};
priority_queue<ty>q;
int bfs(int sx,int sy,int tx,int ty)
{
    memset(vis,0,sizeof(vis));
    q.push({sx,sy,sx,sy,0});
    while(!q.empty())
    {
        struct ty temp=q.top();
        q.pop();
        vis[temp.x][temp.y]=1;
        int x=temp.x;
        int y=temp.y;
        if(x==tx&&y==ty)return temp.dis;
        for(int i=0;i<4;i++)
        {
            int a=x + dx[i],b=y+dy[i];
            if(a>n||a<=0||b>n||b<=0)continue;
            if(g[a][b]=='x')continue;
            if(vis[a][b])continue;
            int add=0;
            if(temp.prex!=a&&temp.prey!=b)
            {
                add++;
            }
            q.push({a,b,x,y,temp.dis+add});
        }
    }
    return -1;
}
int main()
{
    int sx,sy,tx,ty;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='A')
                sx=i,sy=j;
            if(g[i][j]=='B')
                tx=i,ty=j;
        }
    cout<<bfs(sx,sy,tx,ty)<<endl;;
}