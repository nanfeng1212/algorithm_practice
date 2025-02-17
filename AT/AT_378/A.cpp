#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
  map<int,int>mp;
  mp.clear();
  for(int i=1;i<=4;i++){
    int a;
    cin >> a;
    mp[a]++;
  }
  int ans = 0;
  for(auto [x,y]:mp){
    ans += y/2;
  }
  cout << ans << '\n';

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
