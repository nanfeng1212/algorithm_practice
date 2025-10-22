#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,q;

int vis[200010];
int ans[100010];
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op==1) {
            int x,l,r;
            cin >> x >> l >> r;
            for (int j=l; j<=r; j++) {
                if (vis[j]==0) {
                    vis[j] = x;
                    ans[x] ++;
                }
                else {
                    if (vis[j]==x) continue;
                    ans[vis[j]--];
                    vis[j] = x;
                    ans[x]++;
                }
            }
        }
        else if (op==2) {
            ;
        }
        else if (op==3) {
            ;
        }
        else if (op==4) {
            int w;
            cin >> w;
            if (!w) cout << ans[w] << endl;
            else {
                
            }
        }
        else {
            int res = 0;
            int pos = 0;
            for (int j=1; j<=m; j++) {
                if (res<ans[j]) {
                    res = ans[j];
                    pos = j;
                }
            }
            cout << pos << endl;
        }
    }
}   
