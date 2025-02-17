#include<bits/stdc++.h>
using namespace std;
int t,n,m,tot;
int head[1010];
int dis[1010];
int vis[1010];
struct ty{
    int y,l,next;
}edge[2010];
void addedge(int x,int y,int z)
{
    edge[++tot].l=z;
    edge[tot].y=y;
    edge[tot].next=head[x];
    head[x]=tot;
}
struct ty1{
    int x,dis;
    bool operator<(const ty1 &a)const{
        return dis>a.dis;
    }
};
priority_queue<ty1>q;
int dfs(int k)
{
    int max1=0,max2=0;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    ty1 temp;
    temp.x=k,temp.dis=0;
    dis[k]=0;
    q.push(temp);
    while(!q.empty())
    {
        ty1 temp=q.top();
        q.pop();
        if(vis[temp.x])continue;
        vis[temp.x]=1;
        max2=max(max2,dis[temp.x]);
        for(int i=head[temp.x];i!=-1;i=edge[i].next)
        {
            int j=edge[i].y;
            //cout<<dis[j]<<endl;
            if(vis[j])continue;
            if(dis[j]>dis[temp.x]+edge[i].l)
            {
                dis[j]=dis[temp.x]+edge[i].l;
                //cout<<dis[j]<<' '<<dis[temp.x]<<' '<<edge[i].l<<endl;
                ty1 temp2;
                temp2.x=j,temp2.dis=dis[j];
                q.push(temp2);
            }
        }
        if(max1<max2)swap(max1,max2);
    }
    if(max2==0)return -1;
    else return max1+max2;
    
}
int main()
{
    cin>>t;
    while(t--)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            addedge(x,y,z);
            addedge(y,x,z);
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
            ans=max(ans,dfs(i));
        cout<<ans<<endl;
    }
}