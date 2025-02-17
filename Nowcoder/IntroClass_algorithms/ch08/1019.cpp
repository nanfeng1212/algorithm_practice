#include<bits/stdc++.h>
using namespace std;
int n;
int a[12][12];
int dp[1<<12];
int main(){
    while(cin>>n)
    {
        if(n==0)break;
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
               cin >> a[i][j];
        int len = (1 << n)-1;
        for(int i = 0; i <= len; i++)
            for(int j = 1; j <= n; j++)
            {
                int jj = 1 << (j-1);
                if(i & jj)continue;
                for(int k = 1; k <= n; k++)
                {
                    int kk = 1 << (k-1);
                    if(i& kk)continue;
                    if(kk==jj)continue;
                    dp[i|jj]=max(dp[i|jj], dp[i]+a[k][j]);
                }
            }
        int ans=0;
        for(int i = 1; i <= n; i++)
        {
            int ii = (1 << (i-1));
            ans=max(ans,dp[ii^len]);
        }
        cout << ans << endl;
    }
}