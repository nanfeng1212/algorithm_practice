#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ty {
    int fa = -1;
    int ma = -1;
    int sex = -1;
}a[100010];
set<int>s;
int flag = 1;
void dfs(int x, int d) {
    if(d>=6)return;
    if (s.count(x))flag = 0;
    s.insert(x);
    if (a[x].fa!=-1) dfs(a[x].fa,d+1);
    if (a[x].ma!=-1) dfs(a[x].ma,d+1);
}
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int id,fa,ma;
        char sex;
        cin >> id >> sex >> fa >> ma;
        
        a[id].fa = fa;
        a[id].ma = ma;
        if(fa!=-1)a[fa].sex = 1;
        if(ma!=-1)a[ma].sex = 0;
        if (sex=='M')a[id].sex = 1;
        else a[id].sex = 0;
    }
    int k;
    cin >> k;
    while(k--) {
        int p,q;
        cin >> p >> q;
        s.clear();
        flag = 1;
        if (a[p].sex==a[q].sex)cout << "Never Mind\n";
        else{
            dfs(p,1);
            dfs(q,1);
            if(flag)
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
}