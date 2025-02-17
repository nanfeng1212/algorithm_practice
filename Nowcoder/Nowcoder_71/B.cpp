#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main(){
   int t;
    cin >> t;
    while(t--){
        int n;
        mp.clear();
        cin >> n;
        string s;
        cin >> s;
        s+=s;
        int ans = 2*n;
        int flag = 0;
        for(int i=0;i<=2*n-2;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = i;
            }
            else{
                ans = min(ans,i-mp[s[i]]-1);
                mp[s[i]] = i;
            }
        }
        if(mp.size()==n)cout << -1 << endl;
        else{
            cout << ans << endl;
        }
    }
}