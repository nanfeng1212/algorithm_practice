#include<bits/stdc++.h>
using namespace std;

int fa[100010];
int dep[100010];
vector<int>e[100010];

void dfs(int x, int d) {
    dep[x] = d;
    for (auto i:e[x]) {
        dfs(i, d+1);
    }
}
int st[100010];
int main() {
    int n,m;
    cin >> n >> m;
    int r;
    for (int i=1; i<=n; i++) {
        cin >> fa[i];
        if (fa[i]==-1) r = i;
        e[fa[i]].push_back(i);
    }
    dfs(r,0);
    int ans = 0;
    int res = 0;
    while (m--) {
        int x;
        cin >> x;
        ans = max(ans, dep[x]);
        while (!st[x]&&x!=r) {
            st[x] = 1;
            res += 2;
            x = fa[x];
        }

        cout << res-ans << endl;
    }
}