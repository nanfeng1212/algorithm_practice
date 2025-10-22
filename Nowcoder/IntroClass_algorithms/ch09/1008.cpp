/*#include<bits/stdc++.h>
using namespace std;
int n,m,tot=0;
int head[100010];
struct ty{
    int t,l,next;
}edge[2*500000+20];
void addedge(int x,int y,int z)
{
    edge[++tot].t=y;
    edge[tot].l=z;
    edge[tot].next=head[x];
    head[x]=tot;
}
int vis[100010];
struct ty1{
    int x,l;
    bool operator<(const ty1 &a)const
    {
        return l>a.l;
    }
};
int ans=0;
int dis[100010];
priority_queue<ty1>q;
int prim()
{
    vis[1]=1;
    memset(dis,0x3f,sizeof(dis));
    for(int i=head[1];i!=-1;i=edge[i].next)
    {
        ty1 temp;
        temp.x=edge[i].t;temp.l=edge[i].l;
        q.push(temp);
        dis[temp.x]=temp.l;
    }
    while(!q.empty())
    {
        ty1 temp=q.top();
        q.pop();
        if(vis[temp.x])continue;
        vis[temp.x]=1;
        ans+=temp.l;
        for(int i=head[temp.x];i!=-1;i=edge[i].next)
        {
            int y=edge[i].t;
            if(vis[y])continue;
            if(dis[y]>edge[i].l)
            {
                ty1 temp2;
                dis[y]=edge[i].l;
                temp2.x=y;temp2.l=edge[i].l;
                q.push(temp2);
            }
        }
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)
    {
        int a,b,v;
        cin>>a>>b>>v;
        addedge(a,b,v);
        addedge(b,a,v);
    }
    cout<<prim();
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ty{
    int x,y,l;
}edge[500010];
bool cmp(ty x,ty y)
{
    return x.l<y.l;
}
int fa[100010];
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>edge[i].x>>edge[i].y>>edge[i].l;
    sort(edge+1,edge+1+m,cmp);
    int cnt=0;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int a=edge[i].x,b=edge[i].y;
        int fx=find(a),fy=find(b);
        if(fx==fy)continue;
        ans+=edge[i].l;
        fa[find(a)]=find(b);
        cnt++;
        if(cnt>=n-1)break;
    }
    cout<<ans;
    return 0;
}