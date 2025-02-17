#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<ll> S(n+1,0);
  for (int i = 1; i <= n; i++) {
    S[i] = S[i-1] + a[i];
  }
  vector<ll> sum_S(n+1,0);
  for(int i=1;i<=n;i++)
    sum_S[i] = sum_S[i-1] +S[i];
  ll sum = sum_S[n];
  vector<ll> part{0LL};
  vector<ll> part_s{0LL};
  ll cur_len = 0;
  ll cur = 0;
  for (int i = 0; i < n; i++) {
    cur_len += n-i;
    cur += sum;
    part.push_back(cur_len);
    part_s.push_back(cur);
    sum -= a[i+1]*(n - i);
  }
  auto prefix_sum = [&](ll x) -> ll {
    int idx = upper_bound(part.begin(),part.end(),x)-part.begin()-1;
    ll where = part[idx];
    ll ret = part_s[idx];
    ll rem = x - where;
    ret += sum_S[idx + rem] - sum_S[idx] - S[idx] * rem;
    return ret;
  };

  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << prefix_sum(r) - prefix_sum(l - 1) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
