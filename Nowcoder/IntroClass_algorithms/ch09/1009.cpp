#include<bits/stdc++.h>
using namespace std;
int n,m;
struct ty{
    int x,y,w;
}edge[2000010];
bool cmp(ty x,ty y)
{
    return x.w<y.w;
}
int fa[2000010];
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>edge[i].x>>edge[i].y>>edge[i].w;
    sort(edge+1,edge+1+m,cmp);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int l=i,r=i;
        while(r<=m&&edge[i].w==edge[r+1].w)r++;
        for(int j=l;j<=r;j++)
        {
            int a=find(edge[j].x),b=find(edge[j].y);
            if(a!=b)
                ans+=edge[j].w;
        }
        for(int j=l;j<=r;j++)
        {
            int a=find(edge[j].x),b=find(edge[j].y);
            if(b!=a){
                fa[a]=b;ans-=edge[j].w;
            }
        }
    }
        cout<<ans<<endl;
        return 0;

}