#include<bits/stdc++.h>
using namespace std;
int n,m,c,tot=0;
int head[100010],vis[100010];
struct ty{
    int t,v,next;
}edge[5000010];
void addedge(int x,int y,int z)
{
    edge[++tot].t=y;
    edge[tot].v=z;
    edge[tot].next=head[x];
    head[x]=tot;
}
int cost[100010];
struct ty1{
    int cos,x;
    bool operator<(const ty1 &a)const{
        return cos>a.cos;
    }
};
priority_queue<ty1>q;
int bfs(int s,int t)
{
    memset(vis,0,sizeof(vis));
    memset(cost,0x3f,sizeof(cost));
    ty1 temp;
    cost[s]=0;
    temp.x=s,temp.cos=0;
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
            if(cost[y]>cost[temp.x]+edge[i].v){
                cost[y]=cost[temp.x]+edge[i].v;
                ty1 temp2;
                temp2.x=y;
                temp2.cos=cost[y];
                if(!vis[y]);
                q.push(temp2);
            }
        }
    }
    return cost[t];
}
int main(){
    cin>>n>>m>>c;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        addedge(x,y,z);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j<<=1){
            if((i^j)>n)continue;
            addedge(i,(i^j),j*c);
        }
    }
    int s,t;
    cin>>s>>t;
    cout<<bfs(s,t);
    return 0;
}