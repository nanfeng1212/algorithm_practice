#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string s;
  cin >> s;
  long long ans = 0;
  for (int i=0; i<s.length(); i++) {
      for (int j=i+1; j<s.length(); j++) {
          int l = i, r = j;
          int flag = 0;
          while (l<r) {
              if (s[l]>s[r]){
                  flag = 1;
                  break;
              }
              else if (s[l]<s[r])break;
              else l++,r--;
          }
          //cout << i << ' ' << j << ' ' << flag << endl;
          ans += flag;
      }
  }
  cout << ans;
  return 0;
}