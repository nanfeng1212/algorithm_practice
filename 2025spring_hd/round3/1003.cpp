#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(m);
        for (int j=0; j<m; j++) {
            cin >> a[j];
        }
        vector<vector<long long>> c(n, vector<long long>(m));
        vector<vector<long long>> w(n, vector<long long>(m));
        vector<long long> sum_w(m, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> c[i][j];
            }
            for (int j = 0; j < m; ++j) {
                cin >> w[i][j];
                sum_w[j] += w[i][j];
            }
        }
        bool chu = false;
        for (int i=0; i<n; i++) {
            bool flag= true;
            for (int j=0; j<m; j++) {
                if (c[i][j] > a[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                chu = true;
                break;
            }
        }
        if (!chu) {
            cout << "NO\n";
            continue;
        }
        bool ans = true;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                long long sum = a[j] + sum_w[j];
                if (c[i][j] > sum) {
                    ans = false;
                    break;
                }
            }
            if (!ans) break;
        }

        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}