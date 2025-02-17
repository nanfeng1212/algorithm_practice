#include<bits/stdc++.h>
using namespace std;
long long t[200010];
int main(){
      int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    long long ans = 1e18;
    vector<int> order{0, 1, 2};
    do {
        vector dp(n + 1,  vector<long long>(3, 1e18));
        dp[0] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i + 1][order[j]] =  min(dp[i + 1][order[j]], dp[i][order[k]] + (s[i] - '0' != order[j]) * a[i]);
                }
            }
        }
        ans =  min(ans, * min_element(dp[n].begin(), dp[n].end()));
    } while ( next_permutation(order.begin(), order.end()));

    cout << ans << '\n';


}