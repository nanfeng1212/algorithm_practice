#include <bits/stdc++.h>
using namespace std;

int n,k;
int main() {
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int a[26];
    memset(a, 0, sizeof(a));
    for(int i=0; i<s.length(); i++) a[s[i]-'a']++;
    char c = '0';
    for(int i=0; i<26; i++){
      if(a[i]>=2&&a[i]%2==0){
        c = 'a'+i;
        break;
      }
    }
    if(c=='0')cout<<-1<<endl;
    else cout<<c<<endl;
  }
  return 0;
}
