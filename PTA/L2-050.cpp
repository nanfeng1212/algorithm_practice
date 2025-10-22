#include<bits/stdc++.h>
using namespace std;

map<string, vector<string>>mp;
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i=1; i<=n; i++) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string a = "";
        string b;
        while (ss >> b)
            a += b[0];
        mp[a].push_back(s);
    }
    int m;
    cin >> m;
    getchar();
    while (m--) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string a = "";
        string b;
        while (ss >> b)
            a += b[0];
        sort(mp[a].begin(),mp[a].end());
        if (mp[a].size()) {
            for (int i=0;  i<mp[a].size(); i++) {
                if (i==0) cout << mp[a][i];
                else cout << '|' << mp[a][i];
            }
            cout << endl;
        }
        else cout << s << endl;
    }
}