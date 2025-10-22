#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
int tot=0;
bool vis[1000010];
int dis[1000010];
//建图
struct ty{
    int t,l,next;
}edge[1000010];
int head[1000010];
void addedge(int x,int y,int z)
{
    edge[++tot].l=z;
    edge[tot].t=y;
    edge[tot].next=head[x];
    head[x]=tot;
}
//dijkstra方法
/*struct ty1{
    int x,l;
    bool operator<(const ty1 &a)const{
        return l>a.l;
    }
};
priority_queue<ty1>q;
void dij(int s,int t)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    ty1 temp;
    temp.x=s,temp.l=0;
    q.push(temp);
    while(!q.empty())
    {
        ty1 temp=q.top();
        q.pop();
        if(vis[temp.x])continue;
        vis[temp.x]=1;
        for(int i=head[temp.x];i!=-1;i=edge[i].next)
        {
            int y=edge[i].t;
            if(vis[y])continue;
            if(dis[y]>dis[temp.x]+edge[i].l)
            {
                dis[y]=dis[temp.x]+edge[i].l;
                ty1 temp2;
                temp2.x=y,temp2.l=dis[y];
                q.push(temp2);
            }
        }
    }
    if(dis[t]>=0x3f3f3f3f)cout<< -1;
    else cout<<dis[t];
}*/
//spfa方法
queue<int>q;
void spfa(int s,int t)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];~i;i=edge[i].next)
        {
            int y=edge[i].t;
            if(dis[y]>dis[x]+edge[i].l)
            {
                dis[y]=dis[x]+edge[i].l;
                if(!vis[y]){
                    q.push(y);
                    vis[y]=1;
                }
            }
        }
    }
    if(dis[t]>=0x3f3f3f3f)cout<<-1;
    else cout<<dis[t];
}
int main()
{
    cin>>n>>m>>s>>t;
    memset(head,-1,sizeof(head));
    //分别以站台，每条线上的站来当节点
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=1;j<=c;j++)
        {
            int x,last;cin>>x;
            if(j!=1)
            {
                addedge((i-1)*n+x,(i-1)*n+last,b);
                addedge((i-1)*n+last,(i-1)*n+x,b);
            }
            addedge(n*m+x,(i-1)*n+x,a);
            addedge((i-1)*n+x,n*m+x,0);
            last=x;
        }
    }
    //dij(n*m+s,n*m+t);
    spfa(n*m+s,n*m+t);
    return 0;
    
}
