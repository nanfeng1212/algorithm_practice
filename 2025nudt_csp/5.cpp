#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int ans = 0x3f3f3f3f3f;
    int n;
    ll l;
    cin >> n >> l;
    ll v[100010],m[100010];
    ll sum[100010];
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        sum[i] = sum[i-1]+v[i];
    }
    for (int i=1; i<=n ;i++) {
        cin >> m[i];
    }
    cout << (sum[n]-l)*(sum[n]-l);

}
