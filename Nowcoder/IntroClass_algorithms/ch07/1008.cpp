#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
long long  a[30][30]={0};
long long  b[30][30]={0};
int dir[9][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{0,0}};
int main(){
    cin>>n>>m>>x>>y;
    for(int i=0;i<9;i++)
    {
        int dx=x+dir[i][0];
        int dy=y+dir[i][1];
        if(dx<0||dy<0||dx>n||dy>m)continue;
        a[dx][dy]=-1;
    }
   for(int i=0;i<=n;i++)
    {
        if(a[i][0]==-1)
            break;
        b[i][0]=1;
    }
    for(int j=0;j<=m;j++)
    {
        if(a[0][j]==-1)
            break;
        b[0][j]=1;
    }
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<b[i][j]<<' ';
        cout<<endl;
        }*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==-1)b[i][j]=0;
            else b[i][j]=b[i-1][j]+b[i][j-1];
        }
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<b[i][j]<<' ';
        cout<<endl;
        }*/
    cout<<b[n][m]<<endl;
    return 0;
}