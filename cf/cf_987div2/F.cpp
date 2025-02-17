#include<bits/stdc++.h>
using namespace std;
mt19937_64 eng(chrono::steady_clock::now().time_since_epoch().count());
constexpr int maxn = 1e2 + 10;
pair<int, int> query(vector<int> a) {
    cout << "? " << a.size();
    for (int x : a)cout << ' ' << x;
    cout << endl;
    int x, y;
    cin >> x >> y;
    return make_pair(x, y);
}
void solve() {
    int n;
    cin >> n;
    int x0 = 0, y0 = 0;
    do {
        int x = eng() % n + 1, y;
        do {
            y = eng() % n + 1;
        } while (y == x);
        vector<int> vec;
        for (int i = 1; i <= n; i++) {
            if (i == x || i == y) continue;
            vec.push_back(i);
        }
        if(query(vec) == make_pair(n / 2, n / 2 + 1)) {
            x0 = x, y0 = y;
        }
    } while (! x0);
    pair<int, int> c[2] = {{0, 0}, {0, 0}};
    for (int i = 1, j = 0, k = 0; i <= n; i++) {
        if (i == x0 || i == y0) continue;
        if (j) {
            auto [x, y] = query({i, j, x0, y0});
            if (x == n / 2 || x == n / 2 + 1 || y == n / 2 || y == n / 2 + 1) {
            c[k++] = {i, j};
            }
            j = 0;
        } else {
            j = i;
        }
    }
    if (! c[1].first) {
        cout << "! " << c[0].first << ' ' << c[0].second << std::endl;
    } else if (query({c[0].first, c[1].first, x0, y0}) == std::make_pair(n / 2, n / 2 + 1)) {
        cout << "! " << c[0].first << ' ' << c[1].first << std::endl;
    } else if (query({c[0].first, c[1].second, x0, y0}) == std::make_pair(n / 2, n / 2 + 1)) {
        cout << "! " << c[0].first << ' ' << c[1].second << std::endl;
    } else if (query({c[0].second, c[1].first, x0, y0}) == std::make_pair(n / 2, n / 2 + 1)) {
        cout << "! " << c[0].second << ' ' << c[1].first << std::endl;
    } else {
        cout << "! " << c[0].second << ' ' << c[1].second << std::endl;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
