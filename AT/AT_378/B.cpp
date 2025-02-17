#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ty{
  long long q,r;
}a[110];
void solve(){
  map<int,int>mp;
  mp.clear();
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
    cin>>a[i].q>>a[i].r;
  int Q;
  cin >> Q;
  while(Q--){
    int t;
    long long d;
    cin >> t >> d;
    long long q = a[t].q;
    long long r = a[t].r;
    if(d<=r)cout<<r<<endl;
    else{
      int l = d%q;
      if(l<=r)cout<<d/q*q+r<<endl;
      else cout<<d/q*q+q+r<<endl;
    }
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
