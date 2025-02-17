#include <bits/stdc++.h>
using namespace std;
vector<pair<char,int>>mp;
int cnt[26];
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        mp.push_back({s[i],i});
        cnt[s[i]-'a']++;
    }
    int m = 0;
    for(auto i : cnt)
        m = max(m, i);
    if (m > s.length()/2){
        cout << -1 << endl;
        return 0;
    }
    sort(mp.begin(),mp.end(),[&](pair<char,int>x,pair<char,int>y){
      return x.first<y.first;  
    });
    for (int i = 0; i < s.length(); i++){
        int k = mp[(i+m)%s.length()].second;
        s[k] = mp[i].first;
    }
    cout << s << endl;
        
}