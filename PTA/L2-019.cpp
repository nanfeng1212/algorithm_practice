#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string,int>mp;
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        mp[s] = 1;
    }    
    int m;
    cin >> m;
    double sum = 0;
    vector<pair<string,int>>v;
    for (int i=1; i<=m; i++) {
        string s;
        double k;
        cin >> s >> k;
        sum += k;
        v.push_back({s,k});
    }
    sum /= m;
    vector<string>ans;
    for (auto i:v)
        if (i.second>sum&&!mp[i.first])ans.push_back(i.first);
    if (ans.size()) {
        sort(ans.begin(),ans.end());
        for (auto i:ans) cout << i << endl;
    }
    else {
        cout << "Bing Mei You";
    }    
}