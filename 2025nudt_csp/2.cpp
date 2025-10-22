#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[35];
int ans = 0x3f3f3f3f;
int res = 0;
int n,x;
void dfs(int k) {
    //cout << k << ' '  << res << ' ' << ans<< endl;
    if (ans==x) return;
    if (res>=ans) return;
    if (res>=x&&res<ans) {
        ans = res;
        return ;
    }
    if (k>n)return;
    for (int i=0; i<=1; i++){
        if (!i) {
            res += a[k];
            dfs(k+1);
            res -= a[k];
        }
        else {
            dfs(k+1);
        }
    }
}
int main() {
    cin >> n >> x;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    dfs(1);
    cout << ans << endl;
}
