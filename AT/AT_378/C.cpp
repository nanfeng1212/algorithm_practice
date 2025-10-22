#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
  map<int,int>mp;
  mp.clear();
  int n;
  cin >> n;
  int a;
  vector<int>b(n+1);
  for(int i=1;i<=n;i++){
    cin >> a;
    if(mp.find(a)==mp.end()){
      b[i] = -1;
    }
    else{
      b[i] = mp[a];
    }
    mp[a] = i;
  }  
  for(int i=1;i<=n;i++){
    cout << b[i] << " ";
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
