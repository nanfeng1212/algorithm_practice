#include<bits/stdc++.h>
using namespace std;

int n, m;
int e[210][210];
map<pair<int,int>,int>mp;
int main() {
    cin >> n >> m;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++) 
            e[i][j] = 1e9;
    for (int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u][v] = e[v][u] = min(w,e[u][v]);
    }
    int k;
    cin >> k;
    vector<pair<int,int>>ans;
    for (int i=1; i<=k; i++) {
        int cur = 0;
        int res = 0;
        int cnt;
        cin >> cnt;
        int flag = 1;
        set<int>s;
        while (cnt--) {
            int now;
            cin >> now;
            if (e[cur][now]!=1e9 && !s.count(now)) {
                res += e[cur][now];
                cur = now;
                s.insert(cur);
            }
            else
                flag = 0;
        }
        if (e[cur][0]==1e9||s.size()!=n) flag = 0;
        if (!flag) continue;
        //cout << cur << ' ' << res << ' ' << e[cur][0] << endl;
        res += e[cur][0];
        ans.push_back({i,res});
    }
    int res = 1e9+1;
    int idx = 0;
    cout << ans.size() << endl;
    for (auto i:ans) {
        if (i.second<res) {
            idx = i.first;
            res = i.second;
        }
    }
    cout << idx << ' ' << res;

}