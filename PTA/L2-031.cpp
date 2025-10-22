#include<bits/stdc++.h>
using namespace std;

int n;
int ru[100010];
vector<int>e[100010];
int dep = 0;
int ans;
void dfs(int x,int dp) {
    if (dp>dep) {
        dep = dp;
        ans = x;
    }
    for(auto i:e[x])dfs(i,dp+1);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int id;
            cin >> id;
            e[i].push_back(id);
            ru[id] = 1;
        }
    }
    int r;
    for (int i=1; i<=n; i++) {
        if (!ru[i]){
            r = i;
            break;
        }
    }
    dfs(r,1);

    cout << ans;
}
