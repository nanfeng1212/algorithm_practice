#include<bits/stdc++.h>
using namespace std;

int fa[1010];
int main() {
    ios::sync_with_stdio(0),cin.tie(),cout.tie();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) 
            cin >> a[i][j];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) continue;
            int f = 1;
            for (int k=1; k<=m; k++) {
                if (a[i][k]>=a[j][k]){
                    f = 0;
                    break;
                }
            }
            if (f) {
                fa[i] = j;
                break;
            }
        }
    }
    for (int i=1; i<=n; i++) cout << fa[i] << endl;
}