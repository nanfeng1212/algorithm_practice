#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll k, ll b, ll c, ll v) {
    if (k == 0) return 0; // 题目保证k是正整数，可以省略
    
    ll d = (b ^ c) % k;
    d = (d + k) % k; // 确保非负

    // 数位DP函数，计算s <= v，s ≡d mod k，并且s ^ c >= b的s的数量
    string s_v;
    ll tmp = v;
    while (tmp) {
        s_v.push_back((tmp & 1) + '0');
        tmp >>= 1;
    }
    if (s_v.empty()) s_v.push_back('0');
    reverse(s_v.begin(), s_v.end());
    int n = s_v.size();

    string s_b;
    tmp = b;
    while (tmp) {
        s_b.push_back((tmp & 1) + '0');
        tmp >>= 1;
    }
    reverse(s_b.begin(), s_b.end());
    int m = s_b.size();

    // 记忆化搜索，处理数位DP
    // dp[pos][mod][tight][s_xor_ge_b]
    unordered_map<ll, ll> memo[70][2][2];
    function<ll(int, ll, bool, bool)> dfs = [&](int pos, ll mod, bool tight, bool ge_b) -> ll {
        if (pos == n) {
            return ge_b && (mod % k == d) ? 1 : 0;
        }
        ll key = mod * 4 + tight * 2 + ge_b;
        if (memo[pos][tight][ge_b].count(key)) {
            return memo[pos][tight][ge_b][key];
        }
        ll res = 0;
        int up = tight ? (s_v[pos] - '0') : 1;
        for (int bit = 0; bit <= up; ++bit) {
            bool new_tight = tight && (bit == up);
            // 计算当前位的c的bit
            ll c_bit = (c >> (n - 1 - pos)) & 1;
            ll s_bit = bit;
            ll y_bit = s_bit ^ c_bit;
            // 更新ge_b的状态
            bool new_ge_b = ge_b;
            if (!ge_b) {
                if (pos < m) {
                    int b_bit = (b >> (m - 1 - pos)) & 1;
                    if (y_bit > b_bit) {
                        new_ge_b = true;
                    } else if (y_bit < b_bit) {
                        continue;
                    }
                } else {
                    if (y_bit > 0) {
                        new_ge_b = true;
                    } else if (pos >= m) {
                        // b的该位是0，y_bit是0，继续判断
                    }
                }
            }
            ll new_mod = (mod * 2 + s_bit) % k;
            res += dfs(pos + 1, new_mod, new_tight, new_ge_b || (pos >= m && !ge_b));
        }
        memo[pos][tight][ge_b][key] = res;
        return res;
    };

    return dfs(0, 0, true, false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll k, b, c, v;
        cin >> k >> b >> c >> v;
        cout << solve(k, b, c, v) << '\n';
    }
    return 0;
}