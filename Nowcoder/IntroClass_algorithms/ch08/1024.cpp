#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef long long ll;
const ll mod = 9999973;
long long ans = 0;
long long dp[110][110][110];//前i行有j列放了一个炮k列放了两个炮；
int main()
{
    cin >> n >> m;
    dp[0][0][0] = 1;//初始化一个没放方案数为1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= m; j++)
            for(int k = 0; k+j <= m; k++)
                if(dp[i][j][k])
                {
                    //i+1行不放棋子
                    dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % mod;
                    //i+1行放一个在没炮的列
                    if(m-j-k >= 1)dp[i+1][j+1][k] = (dp[i+1][j+1][k] + dp[i][j][k]*(m-k-j)) % mod;
                    //i+1行放一个在有一个炮的列
                    if(j >= 1)dp[i+1][j-1][k+1] = (dp[i+1][j-1][k+1] + dp[i][j][k]*j) % mod;
                    //i+1行在没有炮的两列各放一个
                    if(m-j-k >= 2)dp[i+1][j+2][k] = (dp[i][j][k]*((m-j-k)*(m-j-k-1)/2) + dp[i+1][j+2][k]) % mod;
                    //i+1行在没有炮的一列和有一个炮的一列各放一个
                    if(m-j-k >= 1&&j >= 1)dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k]*j*(m-j-k)) % mod;
                    //i+1行1在有一个炮的两列各放一个
                    if(j >= 2)dp[i+1][j-2][k+2] = (dp[i+1][j-2][k+2] + dp[i][j][k]*((j*(j-1))/2)) % mod;
                }
    for(int i = 0; i <= m; i++)
        for(int j = 0; j+i <= m;j++)
            ans = (ans+dp[n][i][j])%mod;
    cout << ans;
    return 0;
}