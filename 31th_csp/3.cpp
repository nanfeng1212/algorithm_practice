#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
struct ty {
  ll c;
  map<int, int>mp;    
};
ll mod = 1e9+7;
ll ksm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
ty multi(ty x, ty y) {
    x.c = (x.c*y.c)%mod;
    for (auto i : y.mp) {
        x.mp[i.first] += i.second;
    }
    return x;
}
vector<ty> add(vector<ty>a, vector<ty> b, string s) {
    if (s=="-") {
        for (auto &i : b)
            i.c = (-1)*i.c;
    }
    for (auto i : b) {
        a.push_back({i.c, i.mp});
    }
    return a;
}
vector<ty> mul(vector<ty>a, vector<ty> b) {
    vector<ty> c;
    for (auto i:a) {
        for (auto j:b) {
            c.push_back(multi(i, j));
        }
    }
    
    return c;
}
int id;
vector<ty>a;
stack<vector<ty>>ep;
int v[110];
int main() {
    cin >> n >> m;
    getchar();
    string ss;
    getline(cin, ss);
    stringstream s(ss);
    while (s >> ss) {
        if (ss=="+"||ss=="-"||ss=="*") {
            vector<ty> w = ep.top();
            ep.pop();
            vector<ty> q = ep.top();
            ep.pop();
            if (ss=="+") {
                ep.push(add(q, w, ss));
            }
            else if (ss=="-") {
                ep.push(add(q,w,ss));
            }
            else {
                ep.push(mul(q, w));
            }
        }
        else {
            ty cur;
            cur.c = 1;
            if (ss[0]=='x'){
                ll x = 0;
                for (int i = 1; i < ss.size(); i++) {
                    x = x*10+ss[i]-'0';
                }
                cur.mp[x] = 1;
                ep.push(vector<ty>{cur});
            }
            else {
                ll x = 0;
                for (int i =(ss[0]=='-') ?1:0; i < ss.size(); i++) 
                    x = x*10+ss[i]-'0';
                if (ss[0]=='-') x = (-1)*x;
                cur.c = x;
                ep.push(vector<ty>{cur});
            }
        }
    }
    vector<ty>ans = ep.top();
    while (m--) {
        cin >> id;
        ll res = 0;
        for (int i=1; i<=n; i++) cin >> v[i];
        vector<ty>cur;
        cur = ans;
        for (auto i:cur) {
            if (i.mp.find(id)==i.mp.end()) continue;
            ll tmp = i.c;
            for (auto j:i.mp) {
                if (j.first!=id)
                    tmp = (tmp*ksm(v[j.first], j.second))%mod;
                else {
                    tmp = (tmp*j.second)%mod;
                    tmp = (tmp*ksm(v[j.first], j.second-1))%mod;
                }
            }
            res = (res+tmp+mod)%mod;
        }
        cout << res << endl;
    }
}