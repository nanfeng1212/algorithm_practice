#include <bits/stdc++.h>
using namespace std;

map<int,int>mp;
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        int k;
        cin >> k;
        while(k--){
            int f;
            cin >> f;
            mp[f]++;
        }
    }
    int ans1 = 0, ans2 = 0;
    for (auto [x,y]:mp){
        if (y>ans2){
            ans1 = x;
            ans2 = y;
        }
        else if (y==ans2){
            ans1 = x;
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}