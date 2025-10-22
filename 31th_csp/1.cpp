#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        for (int i=1; i<=n; i++) {
            x += v[i].first;
            y += v[i].second;
        }
        cout << x << ' ' << y << endl; 
    }
}