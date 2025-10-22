#include<iostream>
#include<map>
#include<sstream>
#include<stack>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;

int n,m;
int b[110];
int dp[10100];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> b[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i-j<0)break;
            dp[i] = max(dp[i-j]+b[j],dp[i]);
        }
    }
    cout << dp[n];

    return 0;
}
