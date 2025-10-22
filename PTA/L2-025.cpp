#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int e[10010][10010];
int num[10010];
vector<pair<int,int>>q;
int main(){
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        e[u][v] = 1;
        num[u]++, num[v]++;
        q.push_back({u,v});
        e[v][u] = 1;
    }
    int k;
    cin >> k;
    while (k--) {
        int sum = 0;
        int cnt;
        cin >> cnt;
        set<int>s;
        while (cnt--) {
            int p;
            cin >> p;
            sum += num[p];
            s.insert(p);
        }
        for (int i=0; i<m; i++) {
            int u = q[i].first, v = q[i].second;
            if (s.count(u)&&s.count(v))sum--;
        }
        if (sum==m)cout << "YES\n";
        else cout << "NO\n";
    }
}