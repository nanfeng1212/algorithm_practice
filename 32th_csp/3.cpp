#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> e[2010];
int x[2010][2], fz[2010][2010];
ll w[2010];
ll now[2010];
int fa[2010], block[2010];
int vis[2010];
int n, m;
ll sum;
int c, sz;

void dfs0(int i) {
    if (block[i]) {
        for (int j: e[i])
            dfs0(j);
        return;
    }
    sum += w[i];
    now[i] = w[i];
    for (int j: e[i]) {
        dfs0(j);
        if (!block[j])
            now[i] += now[j];
    }
    sz++;
}

int refresh() {
    sz = 0, c = 0, sum = 0;
    dfs0(1);
    for (int i = 1; i <= n; i++) {
        if (!block[i] && abs(sum-2*now[i])<abs(sum-2*now[c]))
            c = i;
    }
    return c;
}

void dfs1(int p) {
    if (sz == 1) return;
    vis[p] = 1;
    vector<int> dd, dd2;
    for (int i = 1; i <= n; i++) {
        if (fz[p][i] && !block[i]) {
            block[i] = 1;
            dd.push_back(i);
        }
    }
    int l = refresh();
    if (vis[l])l = 0;
    if (l)dfs1(l);
    x[p][0] = l;

    for (int i = 1; i <= n; i++) {
        if (!block[i]) {
            block[i] = 1;
            dd2.push_back(i);
        }
    }
    for (auto i: dd)block[i] = 0;
    int r = refresh();
    if (vis[r])r = 0;
    if (r)dfs1(r);
    x[p][1] = r;

    for (auto i: dd2)block[i] = 0;
    vis[p] = 0;
}

void dfs2(int i) {
    fz[i][i] = 1;
    for (int j: e[i]) {
        dfs2(j);
        for (int k = 1; k <= n; k++)fz[i][k] |= fz[j][k];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        e[fa[i]].push_back(i);
    }
    int rt = refresh();
    dfs2(1), dfs1(rt);
    while (m--) {
        int q, s = rt;
        cin >> q;
        while (s) {
            cout << s << ' ';
            s = x[s][fz[s][q]];
        }
        cout << endl;
    }
    return 0;
}