#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>a;
map<int,vector<int>> mp;
int main() {
    int t;
    cin >> t;
    while (t--) {
        a.clear();
        int n;
        cin >> n;
        for (int i=1;i<=n;i++){
            int x;
            cin >> x;
            mp[x].push_back(i);
            a.push_back(x);
        }
        int ans = 0;
        int cnt = mp[0].size();
        if (cnt==0){
            cout << 0 << endl;
            continue;
        }
        if (cnt>=3) {
            for (int i=cnt-1; i>=2; i--) {
                ans += (i-1)*(i-2)/2*(n-mp[0][i]);
            }
        }
        
    }

}