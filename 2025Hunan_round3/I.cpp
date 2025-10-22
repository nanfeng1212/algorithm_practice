#include<bits/stdc++.h>
#define alls(x) x.begin()+1,x.end()
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> h(n+1),p(n+1);
    for (int i = 1;i <= n;++i) cin >> h[i];
    for (int i = 1;i <= n;++i) cin >> p[i];
    vector<pair<int,int>> check(n+1);
    int maxn = 0;
    int ok = 1;
    for (int i = 1;i <= n;++i) {
        check[i] = {h[i], p[i] - h[i]};
        maxn = max(maxn,p[i]-h[i]);
        if (p[i] < h[i]) ok = 0;
    }
    sort(alls(check));
    for (int i = 2;i <= n;++i){
        if (check[i].second < check[i - 1].second) {
            ok = 0;
            break;
        }

    }
    if (!ok) cout << -1 << '\n';
    else cout << maxn << '\n';
}

int main() {
    cout << fixed << setprecision(12);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}