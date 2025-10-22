#include<bits/stdc++.h>
using namespace std;

vector<int>e[100010];
int d;
int ans = 0;
vector<int> res;
void dfs(int x) {
    res.push_back(x);
    for (auto i:e[x]){
        dfs(i);
    }
}
int main() {
    int n;
    cin >> n;
    int r;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        if (k==0) r = i;
        else e[k].push_back(i);
    }
    int flag = 0;
    for (int i=1; i<=n; i++) {
        if (e[i].size()) {
            if (!d) d = e[i].size();
            else {
                if (d!=e[i].size()) {
                    flag = 1;
                }
            }
            ans = max(ans, int(e[i].size()));
        }
    }
    dfs(r);
    cout << ans << ' ';
    if (flag) cout << "no\n";
    else cout << "yes\n";
    for (int i=0; i<n; i++) {
        if (i==0) cout << res[i];
        else cout << ' ' << res[i];
    }
}