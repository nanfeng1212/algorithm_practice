#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int h[10][10],l[10][10],xiao[10][10];
const int num[10][10]={{0,0,0,0,0,0,0,0,0,0},
                       {0,1,1,1,2,2,2,3,3,3},
                       {0,1,1,1,2,2,2,3,3,3},
                       {0,1,1,1,2,2,2,3,3,3},
                       {0,4,4,4,5,5,5,6,6,6},
                       {0,4,4,4,5,5,5,6,6,6},
                       {0,4,4,4,5,5,5,6,6,6},
                       {0,7,7,7,8,8,8,9,9,9},
                       {0,7,7,7,8,8,8,9,9,9},
                       {0,7,7,7,8,8,8,9,9,9}};
struct ty{
    int x,y;
}k[90];
int cnt=0;
void print()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
void dfs(int dep)
{
    if(dep>cnt)
    {
        print();
        return;
    }
    int x=k[dep].x;
    int y=k[dep].y;
    for(int i=1;i<=9;i++)
    {
        if(h[x][i]==0&&l[y][i]==0&&xiao[num[x][y]][i]==0)
        {
            a[x][y]=i;
            h[x][i]=1,l[y][i]=1,xiao[num[x][y]][i]=1;
            dfs(dep+1);
            h[x][i]=0,l[y][i]=0,xiao[num[x][y]][i]=0;
        }
    }
}

int main()
{
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)k[++cnt].x=i,k[cnt].y=j;
            else{
                h[i][a[i][j]]=1;
                l[j][a[i][j]]=1;
                xiao[num[i][j]][a[i][j]]=1;
            }
        }
    dfs(1);
}