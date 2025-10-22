#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[50];
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  ll m;
  cin >> n >> m;
  c[0] = 1;
  for (int i=1; i<=n; i++) {
    ll a;
    cin >> a;
    c[i] = c[i-1]*a;
  }
  ll sum = 0;
  vector<ll>ans(n+1);
  for (int i=1; i<=n; i++) {
    ll mod = m % c[i];
    mod -= sum;
    ans[i] = mod/c[i-1];
    sum += c[i-1]*ans[i];
  }
  for (int i=1; i<=n; i++) cout << ans[i] << ' ';
  return 0;
}
