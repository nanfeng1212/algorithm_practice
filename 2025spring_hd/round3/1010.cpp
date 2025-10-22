#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n == 0) {
            for (int i = 0; i < m; ++i) {
                ll a, b;
                cin >> a >> b;
            }
            cout << 0 << '\n';
            continue;
        }
        ll max_plus = LLONG_MIN, min_plus = LLONG_MAX;
        ll max_minus = LLONG_MIN, min_minus = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            ll sum = x + y;
            ll diff = x - y;
            if (sum > max_plus) max_plus = sum;
            if (sum < min_plus) min_plus = sum;
            if (diff > max_minus) max_minus = diff;
            if (diff < min_minus) min_minus = diff;
        }

        ll ans = LLONG_MAX;

        for (int i = 0; i < m; ++i) {
            ll a, b;
            cin >> a >> b;
            ll sum_ab = a + b;
            ll diff_ab = a - b;

            ll val1 = sum_ab - min_plus;
            ll val2 = max_plus - sum_ab;
            ll val3 = diff_ab - min_minus;
            ll val4 = max_minus - diff_ab;

            ll current_max = max(max(val1, val2), max(val3, val4));

            if (current_max < ans) {
                ans = current_max;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}