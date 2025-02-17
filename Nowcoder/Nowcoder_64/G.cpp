#include <cstring>
#include <iostream>
#include <vector>

constexpr int MXN = 100005;
using namespace std;
vector<int> v[MXN];
int fa[MXN][31];
long long dep[MXN];
long long n, m;
int a, b, c;
long long cnt[MXN];
long long cnt1[MXN];
void dfs(int root, int fno) {
    // 初始化：第 2^0 = 1 个祖先就是它的父亲节点，dep 也比父亲节点多 1。
    fa[root][0] = fno;
    dep[root] = dep[fno] + 1;
    cnt[1] += dep[root];
    cnt1[root] = 1;
    // 初始化：其他的祖先节点：第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第
    // 2^(i-1) 的祖先节点。
    for (int i = 1; i < 31; ++i)
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    // 遍历子节点来进行 dfs。
    int sz = v[root].size();
    for (int i = 0; i < sz; ++i) {
        if (v[root][i] == fno) continue;
        dfs(v[root][i], root);
        cnt1[root] += cnt1[v[root][i]];
    }
}

void dp(int root, int fno){
    for(int i = 0; i < v[root].size(); i++){
        int k = v[root][i];
        if(k == fno)continue;
        cnt[k] = cnt[root] + n - (long long)2*cnt1[k];
        dp(k, root);
    }
    return;
}

// lca。用倍增算法算取 x 和 y 的 lca 节点。
int lca(int x, int y) {
    // 令 y 比 x 深。
    if (dep[x] > dep[y]) swap(x, y);
    // 令 y 和 x 在一个深度。
    int tmp = dep[y] - dep[x];
    for (int j = 0; tmp; ++j, tmp >>= 1)
        if (tmp & 1) y = fa[y][j];
    // 如果这个时候 y = x，那么 x，y 就都是它们自己的祖先。
    if (y == x) return x;
    // 不然的话，找到第一个不是它们祖先的两个点。
    for (int j = 30; j >= 0 && y != x; --j) {
        if (fa[x][j] != fa[y][j]) {
          x = fa[x][j];
          y = fa[y][j];
        }
    }
    return fa[x][0];
}

void Solve() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dep[0]--;
    dfs(1, 0);
    dp(1, 0);
    while(m--){
        int x,y;
        cin >> x >> y;
        cout << (cnt[x] + cnt[y] - n*(dep[x] + dep[y] - (long long)2*dep[lca(x,y)]))/(long long)2<<endl;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--) Solve();
    return 0;
}