#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using ll = long long;

const int M = 1000009;

int n, m, k;
int a[M];
int l[M], r[M], c[M];
ll ans[M];
int d[M], pos[M];

ll sum[M];
void add(int x, int tp) {
    while(x <= n) {
        sum[x] += tp;
        x += x & -x;
    }
}
ll ask(int x) {
    ll ans = 0;
    while(x) {
        ans += sum[x];
        x -= x & -x;
    }
    return ans;
}
ll qur(int l, int r) {
    return ask(r) - ask(l - 1);
}

void modify(int col) {
    int y = pos[col] - k, x = y - 1, z = y + 1;
    if(x > 0 && a[d[x]] == col) add(d[x], col);
    if(y > 0 && a[d[y]] == col) add(d[y], -2 * col);
    if(z > 0 && a[d[z]] == col) add(d[z], col);
    pos[col] ++;
}
bool cmp1(int x, int y) {
    return r[x]<r[y];
}

bool cmp2(int x, int y) {
    return a[x]==a[y] ? x<y:a[x]<a[y];
}
int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        d[i] = i;
    }
    sort(d + 1, d + 1 + n, cmp2);
    for(int i=1; i<=m; i++){
        cin >> l[i] >> r[i];
        c[i] = i;
    }
    sort(c+1, c+1+m, cmp1);
    for(int i=n; i>=1; i--)
        pos[a[d[i]]] = i;
    int cur = 1;
    for(int i=1; i<=n; i++){
        modify(a[i]);
        while(cur<=m && r[c[cur]]==i) {
            ans[c[cur]] = qur(l[c[cur]], r[c[cur]]);
            cur++;
        }
    }
    for(int i=1; i<=m; i++) cout << ans[i] << endl;
    return 0;
}

