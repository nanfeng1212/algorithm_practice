#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int q[50],z[50];
int ans[100010];
void dfs(int r, int s, int e, int i) {
    if (s>e) return;
    int idx = s;
    while (idx<=e&&z[idx]!=q[r])idx++;
    ans[i] = q[r]; 
    dfs(r+1+idx-s, idx+1, e, 2*i+1);
    dfs(r+1, s, idx-1, 2*i+2);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> z[i];
    for (int i=1; i<=n; i++) cin >> q[i];
    memset(ans,-1,sizeof(ans));
    dfs(1,1,n,1);
    for (int i=1; i<= 100000; i++) {
        if (ans[i]!=-1) {
            if (i!=1)cout << ' ';
            cout << ans[i];
        }
    }
    
}