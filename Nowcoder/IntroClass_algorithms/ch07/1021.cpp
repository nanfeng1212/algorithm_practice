#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=110*100;
int a[110];
int f[110][2*N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=N;j++)
        {
            f[i][j]=f[i-1][j];
            f[i][j]=max(f[i][j],f[i-1][abs(j-a[i])]+a[i]);
            f[i][j]=max(f[i][j],f[i-1][j+a[i]]+a[i]);
        }
    int ans=0;
    for(int i=0;i<=m;i++)
        ans=max(f[n][i],ans);
    cout<<ans;
    return 0;
}