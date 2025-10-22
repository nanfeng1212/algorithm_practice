#include<bits/stdc++.h>
using namespace std;


int a[100010],b[100010];
int pre[100010],suf[100010];
int ans[100010];
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n+1; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    pre[0] = suf[n+2] = -0x3f3f3f;
    for (int i=1; i<=n+1; i++) {
        ans[i] = ans[i-1]+a[i]-b[i-1];
        pre[i] = max(pre[i-1],ans[i]);
    }
    for (int i=n+1; i>=1; i--) {
        suf[i] = max(suf[i+1],ans[i]);
    }
    for (int i=1; i<=n; i++) {
        cout << max(0, max(pre[i],suf[i+1]+b[i])) << ' ';
    }

}