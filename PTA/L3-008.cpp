#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v(10010);
int vis[10010];
int main() {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i < k; i++) {
        cin >> a;
        queue<int> q;
        memset(vis,0,sizeof(vis));
        q.push(a);
        int level[10010];
        int ans = 10010, maxlevel = 0;
        vis[a] = 1;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            if(level[top]>maxlevel) {
                maxlevel = level[top];
                ans = 10010;
            }
            if(top != a)
                ans = min(ans, top);
            for(int j=0; j<v[top].size(); j++) {
                if(vis[v[top][j]]==0) {
                    q.push(v[top][j]);
                    vis[v[top][j]] = 1;
                    level[v[top][j]] = level[top] + 1;
                }
            }
        }
        if(ans != 10010) 
            cout << ans << endl;
        else cout << "0\n";
    }
    return 0;
}