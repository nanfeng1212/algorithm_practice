#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100010], k[100010];
int n;
int vis[100010];
int maxn = 0;
queue<pair<int,int>>q;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    q.push({1,0});
    int ans = -1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        if (x==n) {
            ans = y;
            break;
        }
        if (x+k[x]<=maxn) continue;
        if (x+k[x]>=n) {
            q.push({n, y+1});
            continue;
        }
        for (int i=max(x+1, maxn+1); i<=n&&i<=x+k[x]; i++) {
            q.push({i-a[i], y+1});
        }
        maxn = min(n, x+k[x]);
    }
    cout << ans << endl;
}