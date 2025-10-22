#include<bits/stdc++.h>
using namespace std;
int n,tot;
typedef long long ll;
struct ty{
    int t,next;
    ll c;
}edge[200010];
int head[100010];
void addedge(int x,int y,int z)
{
    edge[++tot].t=y;
    edge[tot].c=z;
    edge[tot].next=head[x];
    head[x]=tot;
}
long long dis1[100010];
void bfs1(int x,int fa)
{
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int y=edge[i].t;
        if(y==fa)continue;
        dis1[y]=dis1[x]+edge[i].c;
        bfs1(y,x);
    }
}
long long dis2[100010];
void bfs2(int x,int fa)
{
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int y=edge[i].t;
        if(y==fa)continue;
        dis2[y]=dis2[x]+edge[i].c;
        bfs2(y,x);
    }
}
int main()
{
    while(cin>>n)
    {
        tot=0;
        memset(dis1,0,sizeof(dis1));
        memset(dis2,0,sizeof(dis2));
        memset(head,-1,sizeof(head));
        for(int i=1;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            addedge(a,b,c);
            addedge(b,a,c);
        }
        int l,r;
        bfs1(1,0);
        ll ans=-0x3f3f3f3f;
        l=1;
        for(int i=2;i<=n;i++)
        {
            if(ans<dis1[i]){
                ans=dis1[i];
                l=i;
            }
        }
        memset(dis1,0,sizeof(dis1));
        bfs1(l,0);
        ans=-0x3f3f3f3f;
        for(int i=2;i<=n;i++)
        {
            //cout<<dis1[i]<<endl;
            if(ans<dis1[i]){
                ans=dis1[i];
                r=i;
            }
        }
       // cout<<r<<endl;
        bfs2(r,0);
        ans=0;
        for(int i=1;i<=n;i++)
            ans+=max(dis1[i],dis2[i]);
        ans-=dis2[l];
        cout<<ans<<endl;
    }
    return 0;
}