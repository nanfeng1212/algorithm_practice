#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;;
long long dp[100][4010];
int main(){
    int x,y;
    cin >> x >> y;
    dp[0][2000] = 1;
    for(int i=1; i<=y+1; i++){
        for(int j=1000; j<=3000; j++){
            if(dp[i-1][j]<=0)continue;
            for(int left = 1; left<=5; left++){
                for(int right=1; right<=5; right++){
                    dp[i][j+left+right] = (dp[i][j+left+right]+dp[i-1][j])%MOD;
                    dp[i][j+left-right] = (dp[i][j+left-right]+dp[i-1][j])%MOD;
                    dp[i][j-left-right] = (dp[i][j-left-right]+dp[i-1][j])%MOD;
                    dp[i][j-left+right] = (dp[i][j-left+right]+dp[i-1][j])%MOD;
                }
            }
            for(int k=1; k<=10; k++){
                dp[i][k+j] = (dp[i][k+j]+dp[i-1][j])%MOD;
                dp[i][j-k] = (dp[i][j-k]+dp[i-1][j])%MOD;
            }
        }
    }
    cout << dp[y+1][x+2000] << endl;
}