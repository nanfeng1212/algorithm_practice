#include<bits/stdc++.h>
using namespace std;
int  n,m,s,t,tot=0;
//vector<int>edge[10010];
int vis[10010];
int head[10010];
int dis[10010];
struct ty{
    int l,t,next;
}edge[20010];
void addedge(int x,int y,int z)
{
    edge[++tot].l=z;
    edge[tot].t=y;
    edge[tot].next=head[x];
    head[x]=tot;
}
struct ty2{
    int x,dis;
    bool operator<(const ty2 &a)const
    {
        return dis>a.dis;
    }
};
priority_queue<ty2>q;
int bfs(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    ty2 temp;
    temp.x=s;temp.dis=0;
    q.push(temp);
    while(!q.empty())
    {
        ty2 temp=q.top();
        q.pop();
        if(vis[temp.x])continue;
        vis[temp.x]=1;
        for(int i=head[temp.x];i!=-1;i=edge[i].next)
        {
            int y=edge[i].t;
            if(vis[y])continue;
            if(dis[y]>dis[temp.x]+edge[i].l){
                dis[y]=dis[temp.x]+edge[i].l;
                ty2 temp2;
                temp2.dis=dis[y],temp2.x=y;
                //cout<<temp.x<<" "<<" "<<dis[y]<<endl;
                q.push(temp2);
            }
        }
    }
    if(dis[t]>=0x3f3f3f3f)return -1;
    return dis[t];
}
int main()
{
    cin>>n>>m>>s>>t;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        addedge(x,y,z);
        addedge(y,x,z);
    }
    cout<<bfs(s,t);
    return 0;
}