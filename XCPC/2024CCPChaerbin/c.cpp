#include<bits/stdc++.h>
using namespace std;

map<char,int>mp;
int main(){
    int t;
    cin >> t;
    mp['N'] = 1;
    mp['W'] = 2;
    mp['S'] = 3;
    mp['E'] = 4;
    while(t--){
        int n;
        cin >> n;
        vector<pair<char,int>>v(n+1);
        for(int i=1;i<=n;i++)
            cin >> v[i].first >> v[i].second;
        cout << 2*n-1 << ' ' << v[1].first << endl;
        int pos = 1;
        cout << 'Z' << ' ' << v[1].second << endl;
        while(pos < n){
            if(mp[v[pos].first]-mp[v[pos+1].first] == -1 || mp[v[pos].first]-mp[v[pos+1].first] == 3){
                cout << 'L' << endl;
                cout << 'Z' << ' ' << v[pos+1].second << endl;
            }
            else{
                cout << 'R' << endl;
                cout << 'Z' << ' ' << v[pos+1].second << endl;
            }
            pos++;
        }
    }
}