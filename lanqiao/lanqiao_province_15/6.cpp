#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,q;
ll sum[100010][30];
ll pa[100010][31];
int dep[100010];
vector<int>e[100010];
void dfs(int r, int x){
    dep[x] = dep[r]+1;
    pa[x][0] = r;
    for (int i=1; i<=20; i++) 
        sum[x][i] += sum[r][i];
    for (int i=1; i<=30; i++) {
        pa[x][i] = pa[pa[x][i-1]][i-1];
    }
    for (auto i:e[x]){
        if (i==r)continue;
        dfs(x,i);
    }
}

int lca(int a, int b) {
    if (a==b) {
        return a;
    }
    if(dep[a]<dep[b])swap(a,b);
    for(int j=30; j>=0; j--)
        if (dep[pa[a][j]]>=dep[b]) {
            a = pa[a][j];
        }
    if (a==b) {
        return a;
    }
    for (int i=30; i>=0; i--) {
        if (pa[a][i]!=pa[b][i]){
            a = pa[a][i];
            b = pa[b][i];
        }
    }
    return pa[a][0];

}
int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        int c;
        cin >> c;
        sum[i][c]=1;
    }
    for (int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0,1);
    while (q--) {
        int s,t;
        cin >> s >> t;
        int ans = lca(s,t);
        int res = 0;
        for (int i=1; i<=20; i++) {
            ll num = sum[s][i]+sum[t][i]-sum[ans][i]-sum[pa[ans][0]][i];
            if (num)res++;
        }
        cout << res << endl;
    }
    return 0;
}