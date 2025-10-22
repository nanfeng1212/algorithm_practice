#include<bits/stdc++.h>
using namespace std;

int x[110],y[110];
int main() {
    int n,m;
    cin >> n  >> m;
    for (int i=1; i<=n; i++) {
        int l;
        cin >> l;
        set<int>s;
        while (l--) {
            int k;
            cin >> k;
            if (s.count(k));
            else s.insert(k), x[k]++;
            y[k]++;
        }
    }
    for (int i=1; i<=m; i++) cout << x[i] << ' ' << y[i] << endl;

}