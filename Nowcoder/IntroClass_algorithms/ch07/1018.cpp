#include<bits/stdc++.h>
using namespace std;
int t,m;
int a[110][4];
int f[110][100010];
int main()
{
    cin>>t>>m;
    
    for(int i=1;i<=m;i++)
        cin>>a[i][1]>>a[i][2];
    for(int i=1;i<=m;i++)
        for(int j=0;j<=t;j++)
        {
           if(j>=a[i][1])
           {
               f[i][j]=max(f[i-1][j],f[i-1][j-a[i][1]]+a[i][2]);
           }
            else f[i][j]=f[i-1][j];
        }
    /*for(int i=1;i<=m;i++)
        for(int j=t;j>=0;j--)
        {
            if(j>=a[i][1])
            f[j]=max(f[j],f[j-a[i][1]]+a[i][2]);
        }*/
    cout<<f[m][t]<<endl;
    return 0;
}