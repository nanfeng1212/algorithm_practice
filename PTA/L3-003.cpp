#include<bits/stdc++.h>
using namespace std;

int fa[1010];
int find(int x) {
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}
int vis[1010];
int ans[1010];
int cnt = 0;
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) fa[i] = i;
    for (int i=1; i<=n; i++) {
        int k;
        char c;
        cin >> k >> c;
        while (k--) {
            int h;
            cin >> h;
            if (vis[h]) {
                fa[find(vis[h])]  = find(i);
            }
            else {
                vis[h]  = i;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        int p = find(i);
        if (ans[p]) ans[p]++;
        else ans[p] = 1, cnt++;
    }
    cout << cnt << endl;
    vector<int>res;
    for (int i=1; i<=n; i++) {
        if (ans[i]) res.push_back(ans[i]);
    }
    sort(res.begin(), res.end());
    for (int i=res.size()-1; i>=0; i--) {
        cout << res[i];
        if (i!=0) cout << ' ';
    }
}