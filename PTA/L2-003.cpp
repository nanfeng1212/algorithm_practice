#include<bits/stdc++.h>
using namespace std;

int n;
int d;
double s[1010];
double a[1010];
double dp[1010][510];
int main() {
    cin >> n >> d;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> s[i];
    for (int k=1; k<=d; k++)
        for (int i=1; i<=n; i++){
            for (int j=0; j<=a[i]; j++) {
                if (k-j<0)break;
                dp[i][k] = max(dp[i][k],dp[i-1][k-j]+j*s[i]/a[i]);
        }
    }
    cout << fixed << setprecision(2) << dp[n][d];
}