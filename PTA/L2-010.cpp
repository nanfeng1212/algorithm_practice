#include <bits/stdc++.h>
using namespace std;
int f[110];
int e[110][110];
int n,m,k;
int find(int x) {
    return f[x]==x ? x:f[x]=find(f[x]);
}
void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b)
        f[a] = b;
}
int main() {
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) f[i] = i;
    int a, b, c;
    for (int i=1; i<=m; i++) {
        cin >> a >> b >> c;
        if (c==1)
            merge(a, b);
        else 
            e[a][b] = e[b][a] = 1;
    }
    while(k--) {
        cin >> a >> b;
        if (find(a) == find(b) && e[a][b] == 0)
            cout << "No problem\n";
        else if (find(a) != find(b) && e[a][b] == 0)
            cout << "OK\n";
        else if (find(a) == find(b) && e[a][b] == 1)
            cout << "OK but...\n";
        else if (e[a][b] == 1)
            cout << "No way\n";
    }
}
