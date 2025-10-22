#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int cnt = 0;
  for (int i=1; i<=100000000; i++) {
      string s = to_string(i);
      if (s.length()%2)continue;
      int r1 = 0, r2 = 0;
      for (int j=0; j<s.length()/2; j++) {
          r1 += s[j]-'0';
      }
      for (int j=s.length()/2; j<s.length(); j++){
          r2 += s[j]-'0';
      }
      if (r1==r2)cnt++;
  }
  cout << cnt << endl;
  return 0;
}