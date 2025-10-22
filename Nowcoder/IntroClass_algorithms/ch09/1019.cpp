#include<bits/stdc++.h>
using namespace std;
int n,m,t;
long long g[310][310];
int main()
{
    cin>>n>>m>>t;
    memset(g,0x3f3f3f3f,sizeof(g));
    for(int i=1;i<=m;i++)
    {
        int x,y;
        long long h;
        cin>>x>>y>>h;
        g[x][y]=min(g[x][y],h);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                //if(k!=j&&k!=i&&i!=j)
                    g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
            }
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(g[x][y]>=0x3f3f3f3f)cout<<-1<<endl;
        else cout<<g[x][y]<<endl;
    }
    return 0;
}