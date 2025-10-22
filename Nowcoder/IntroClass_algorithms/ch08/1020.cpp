#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long mod=100000000;
long long dp[13][1<<13];
long long a[13];
int main()
{
    while(cin>>n>>m)
    {
        memset(a, 0, sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                long long x;
                cin>>x;
                a[i]=(a[i]<<1)+x;
            }
        dp[0][0]=1;
        long long len = (1<<m)-1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= len; j++)
            {
                if((a[i]&j)!=j)continue;
                if (j & (j >> 1))continue;
                for(int k = 0; k<= len; k++)
                {
                    if (k & j)continue;
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        long long ans=0;
        for(int i=0;i<=len;i++)
            ans = (ans+dp[n][i])%mod;
        cout<<ans<<endl;
    }
}