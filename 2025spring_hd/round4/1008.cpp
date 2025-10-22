#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                cin >> a[i][j];
            }
        }
        vector<long long> prev(k, LLONG_MIN);
        prev[0] = 0;
        for (int i = 1; i <= n; ++i) {
            vector<long long> curr(k, LLONG_MIN);
            for (int m = 0; m < k; ++m) {
                if (prev[m] == LLONG_MIN) continue;
                if (m + 1 <= k) {
                    long long val = prev[m] + a[i][m + 1];
                    if (val > curr[m]) {
                        curr[m] = val;
                    }
                }
                if (m < k - 1) {
                    long long val = prev[m] + a[i][m + 2];
                    if (val > curr[m + 1]) {
                        curr[m + 1] = val;
                    }
                }
            }
            prev = move(curr);
        }
        cout << prev[k - 1] << '\n';
    }
    return 0;
}