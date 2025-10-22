#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>e[510];
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int k;
    cin >> k;
    for (int i=1; i<=x; i++) {
        int u,v;
        cin >> u >> v;
        if (u>v)swap(u,v);
        e[u].push_back(v);
    }
    int p;
    cin >> p;
    while (p--) {
        vector<int>c(n+1);
        set<int>s;
        for (int i=1; i<=n; i++){
            cin >> c[i];
            s.insert(c[i]);
        }
        int flag = 1;
        for (int i=1 ;i<n; i++) {
            for (auto j:e[i]){
                if (c[i]==c[j]){
                    flag = 0;
                    break;
                }
            }
        }
        if (flag&&s.size()<=k) cout << "Yes\n";
        else cout <<"No\n";
    }
}