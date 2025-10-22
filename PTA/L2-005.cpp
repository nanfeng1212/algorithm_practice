#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int>s[51];
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int m;
        cin >> m;
        while(m--){
            int p;
            cin >>p;
            s[i].insert(p);
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int c = 0, t = 0;
        int a,b;
        cin >> a >> b;
        for (auto i:s[a])
            if (s[b].count(i))
                c++;
        t = s[a].size()+s[b].size()-c;
        cout << fixed << setprecision(2) << c/double(t)*100 << "%\n";
    }
}