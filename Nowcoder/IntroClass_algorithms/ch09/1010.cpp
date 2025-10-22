#include<bits/stdc++.h>
using namespace std;
struct ty{
    int x,y,h;
}edge[10010];
int fa[110];
bool cmp(ty x,ty y)
{
    return x.h<y.h;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    int c,n,m;
    while(cin>>c>>n>>m)
    {
        for(int i=1;i<=m;i++)fa[i]=i;
        for(int i=1;i<=n;i++)
            cin>>edge[i].x>>edge[i].y>>edge[i].h;
        sort(edge+1,edge+1+n,cmp);
        int cnt=0;
        for(int i=1;cnt<m-1&&c>=0&&i<=n;i++)
        {
            int x=edge[i].x,y=edge[i].y;
            int fx=find(x),fy=find(y);
            if(fx!=fy)
            {
                cnt++;
                c-=edge[i].h;
                fa[fx]=fy;
            }
        }
        if(cnt>=m-1)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}