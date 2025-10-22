#include<bits/stdc++.h>
using namespace std;

set<int>s[100010];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int p;
            cin >> p;
            s[i].insert(p);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a,b;
        cin >> a >> b;
        int ans = 0;
        for (int i=1; i<=n; i++) {
            if (s[i].count(a)&&s[i].count(b))ans++;
        }
        cout << ans << endl;
    }
}