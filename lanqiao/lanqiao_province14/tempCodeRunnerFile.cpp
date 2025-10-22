#include <bits/stdc++.h>
using namespace std;

long long dp[31][11];
int main()
{
  // 请在此输入您的代码
    dp[1][0] = 1, dp[1][1] = 1;
    for (int i=2; i<=30; i++) {
        for (int j=0; j<=9; j++) {
            dp[i][0] += dp[i-1][j];
        }
        for (int j=1; j<=9; j++) {
            dp[i][j] += dp[i-1][j-1];
        }
    }
    long long ans = 0;
    for (int i=7; i<=30; i++) ans += dp[i][7];
    cout << ans << endl;

    return 0;
}