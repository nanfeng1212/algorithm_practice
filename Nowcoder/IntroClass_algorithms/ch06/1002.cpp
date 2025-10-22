#include<bits/stdc++.h>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
char a[510][510];
int v[510][510];
int dir[4][2]={+1,0,-1,0,0,+1,0,-1};
queue<int>p;
int q;
int z;
void bfs(int q)
{
    memset(v,-1,sizeof(v));
    v[q/m][q%m]=0;
    p.push(q);
    while(!p.empty())
    {
        int tmp=p.front();
        int x=tmp/m;
        int y=tmp%m;
        p.pop();
        for(int i=0;i<4;i++)
        {
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if((dx>=0&&dy>=0&&dx<n&&dy<m)&&a[dx][dy]!='#'&&v[dx][dy]==-1)
            {
                v[dx][dy]=v[x][y]+1;
                p.push(dx*m+dy);
            }
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='S')q=i*m+j;
                if(a[i][j]=='E')z=i*m+j;
            }
        bfs(q);
        if(v[z/m][z%m]!=-1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
       // return 0;
        
        
    }
}