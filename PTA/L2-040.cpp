#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>e[100010];
int ans[1000010];

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        e[i].push_back(k);
        for (int j=1; j<=e[i][0]; j++) {
            cin >> k;
            e[i].push_back(k);
        }
    }
    int cur = 1;
    for (int i=1; i<=m; i++){
        int now, j;
        cin >> now >> j;
        if (now==0) {
           // cout << cur << ' ' << j << ' ' << e[cur][j] << endl;
            cur = e[cur][j];
        }
        else if (now==1) {
            ans[j] = cur;
            cout << ans[j] << endl;
        }
        else {
            cur = ans[j];
        }
    }
    cout << cur << endl;
}