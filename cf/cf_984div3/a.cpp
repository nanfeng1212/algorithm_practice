#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int flag = 1;
    for(int i=1;i<n;i++){
        if(abs(a[i]-a[i+1])!=5&&abs(a[i+1]-a[i])!=7)
        {
          flag = 0;
          break;
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
