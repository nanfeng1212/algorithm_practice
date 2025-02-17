#include <bits/stdc++.h>
using namespace std;

int n,k;
int main() {
  int t;
  cin >> t;
  while(t--){
    cin >> n >> k;
    vector<long long>b(k+1,0);
    for(int i=0;i<k;i++){
      int p,q;
      cin >> p >> q;
      b[p]+=q;
    }
    long long ans = 0;
    sort(b.begin(),b.end());
    for(int i=k;i>=0;i--){
      ans+=b[i];
      n--;
      if(n==0)break;
    }
    cout << ans << endl;
  }
  return 0;
}
