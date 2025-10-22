#include <bits/stdc++.h>
using namespace std;

int ans = 35;
long long sum[35];
long long a[35];
int n;
long long m;
void dfs(int x, long long w, int cnt) {
    if (w==m) {
        ans = min(ans,cnt);
        return ;
    }
    if (x>n) return;
    if (cnt>=ans || w>m) return;
    if (w+sum[x]<m) return;
    dfs(x+1, w, cnt);
    dfs(x+1, w+a[x], cnt);
    dfs(x+1, w+a[x]/2, cnt+1);
}
int main()
{
  // 请在此输入您的代码
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i]*=2;
    }
    m *= 2;
    sort(a+1,a+1+n,greater<>());
    for (int i=n; i>=1; i--) sum[i] = sum[i+1]+a[i];
    //cout << 11111;
    dfs(1,0,0);
    if (ans==35)cout << -1;
    else cout << ans;
  return 0;
}