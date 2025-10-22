#include <bits/stdc++.h>
using namespace std;

int n,k;
int main() {
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int q;
    int ans = 0;
    for(int i=0;i<=s.length()-3;i++){
        if((s[i]=='1'&&s[i+1]=='1')&&(s[i+2]=='0'&&s[i+3]=='0'))ans++;
    }
    cin >> q;
    while(q--){
        int i;
        char v;
        cin >> i >> v;
        i--;
        if(s[i]==v){
            //cout << ans << endl;
            if(ans>0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        if(s[i]=='1'){
            if(i+3<s.length())if(s[i+1]=='1'&&(s[i+2]=='0'&&s[i+3]=='0'))ans--;
            if(i-1>=0&&i+2<s.length())if((s[i-1]=='1'&&s[i+1]=='0')&&s[i+2]=='0')ans--;
            if(i-2>=0&&i+1<s.length())if((s[i-2]=='1'&&s[i-1]=='1')&&s[i+1]=='0')ans++;
            if(i-3>=0)if((s[i-3]=='1'&&s[i-2]=='1')&&s[i-1]=='0')ans++;
            s[i] = '0';
        }
        else{
            if(i+3<s.length())if(s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')ans++;
            if(i-1>=0&&i+2<s.length())if(s[i-1]=='1'&&(s[i+1]=='0'&&s[i+2]=='0'))ans++;
            if(i-2>=0&&i+1<s.length())if(s[i-2]=='1'&&(s[i-1]=='1'&&s[i+1]=='0'))ans--;
            if(i-2>=0)if(s[i-3]=='1'&&(s[i-2]=='1'&&s[i-1]=='0'))ans--;
            s[i] = '1';
        }
        //cout << ans << endl;
        if(ans>0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
  }
  return 0;
}
