#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int fa[10010];

int find(int x){
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=10010; i++) fa[i] = i;
    set<int>s;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        int q;
        cin >> q;
        k--;
        s.insert(q);
        while (k--) {
            int p;
            cin >> p;
            s.insert(p);
            int f1 = find(q);
            int f2 = find(p);
            if (f1>f2)swap(f1,f2);
            if (f1!=f2)fa[f2] = f1;
        }
    }
    int ans = 0;
    for (int i:s) {
        if (fa[i]==i)ans++;
    }
    cout << s.size() << ' ' << ans << endl;
    int q;
    cin >> q;
    while (q--) {
        int u,v;
        cin >> u >> v;
        int f1 = find(u);
        int f2 = find(v);
        if (f1!=f2) cout << "N\n";
        else cout << "Y\n";
    }
}