#include<bits/stdc++.h>
using namespace std;

map<string,string>mp1;
map<string,int>mp2;
map<int,int>mp;
vector<string>ans1;
vector<string>ans2;
int main(){
    string l;
    int n;
    cin >> l >> n;
    for (int i=1; i<=n; i++) {
        string d,nx; 
        int v;
        cin >> d >> v >> nx;
        mp1[d] = nx;
        mp2[d] = v;
    }
    string cur = l;
    while(cur!="-1") {
        if (mp.find(abs(mp2[cur]))==mp.end()){
            mp[abs(mp2[cur])] = 1;
            ans1.push_back(cur);
        }
        else{
            ans2.push_back(cur);
        }
        cur = mp1[cur];
    }
    for (int i=0; i<ans1.size()-1; i++) {
        cout << ans1[i] << ' ' << mp2[ans1[i]] << ' ' << ans1[i+1] << '\n';
    }
    cout << ans1[ans1.size()-1] << ' ' << mp2[*ans1.rbegin()] << ' ' << "-1\n";
    if(ans2.size()) {
        for (int i=0; i<ans2.size()-1; i++) {
            cout << ans2[i] << ' ' << mp2[ans2[i]] << ' ' << ans2[i+1] << '\n';
        }
        cout << ans2[ans2.size()-1] << ' ' << mp2[*ans2.rbegin()] << ' ' << "-1\n";
    }
}