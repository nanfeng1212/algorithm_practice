#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int h[50],z[50];
int ans[100010];
void dfs(int r, int s, int e, int i) {
    if (s>e) return;
    int idx = s;
    while (idx<=e&&z[idx]!=h[r])idx++;
    ans[i] = h[r]; 
    dfs(r-(e-idx)-1, s, idx-1, 2*i+1);
    dfs(r-1, idx+1, e, 2*i+2);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> h[i];
    for (int i=1; i<=n; i++) cin >> z[i];
    memset(ans,-1,sizeof(ans));
    dfs(n,1,n,1);
    for (int i=1; i<= 100000; i++) {
        if (ans[i]!=-1) {
            if (i!=1)cout << ' ';
            cout << ans[i];
        }
    }
    
}