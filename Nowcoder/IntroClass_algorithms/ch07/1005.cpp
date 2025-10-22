#include<bits/stdc++.h>
using namespace std;
int f,v;
int a[110][110];
int pos[110];
int dp[110][110];
int main(){
    cin>>f>>v;
    for(int i=1;i<=f;i++)
        for(int j=1;j<=v;j++)
            cin>>a[i][j];
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=f;i++)
        for(int j=i;j<=v-(f-i);j++)
            for(int k=i-1;k<j;k++)
                dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=v;i++)
        ans=max(ans,dp[f][i]);
    cout<<ans<<endl;
    for(int i=f;i>=1;i--)
        for(int j=1;j<=v;j++)
        {
            if(dp[i][j]==ans){
                pos[i]=j;
                ans-=a[i][j];
                break;
            }
        }
    for(int i=1;i<=f;i++)
        cout<<pos[i]<<' ';
    cout<<endl;
}