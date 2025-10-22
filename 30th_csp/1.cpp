#include<bits/stdc++.h>
using namespace std;

map<string,int>mp;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        for (int j=1; j<=8; j++) {
            string ss;
            cin >> ss;
            s += ss;
        }
        mp[s]++;
        cout << mp[s] << endl;
    }
}