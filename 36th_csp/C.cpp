#include<bits/stdc++.h>
using namespace std;

int n,N,q;
struct ty{
    int t;
    int cnt;
    long long id;
    bool operator<(const ty& b) const {
        if (t != b.t) return t < b.t;
        return cnt < b.cnt;
    }
};
map<long long, int>cnt;
map<long long, int>vis;
map<long long, int>t;
map<long long,int>change;
set<ty> s[65540];
int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> N >> q;
    for (int i=1; i<=q; i++) {
        int o;
        long long a;
        cin >> o >> a;
        //cout << a/n%n+1 << endl;
        if (o == 0) {
            if (vis[a]) {
                s[vis[a]].erase({t[a], cnt[a], a});
                t[a] = i;
                cnt[a]++;
                s[vis[a]].insert({t[a], cnt[a], a});
            }
            else {
                vis[a] = (a/n%N)+1;
                t[a] = i;
                cnt[a]++;
                if (s[vis[a]].size() == n) {
                    auto it = s[vis[a]].begin();
                    int del = it->id;
                    s[vis[a]].erase({it->t, it->cnt, it->id});
                    vis[del] = 0;
                    t[del] = 0;
                    if (change[del]) {
                        cout << 1 << ' ' << del << endl;
                        change[del] = 0;
                    }
                }
                s[vis[a]].insert({t[a], cnt[a], a});
                cout << 0 << ' ' << a << endl;
            } 
        }
        else {
            if (vis[a]) {
                change[a] = 1;
                s[vis[a]].erase({t[a], cnt[a], a});
                cnt[a]++;
                t[a] = i;
                s[vis[a]].insert({t[a], cnt[a], a});
            }
            else {
                vis[a] = (a/n%N)+1;
                t[a] = i;
                cnt[a]++;
                if (s[vis[a]].size() == n) {
                    auto it = s[vis[a]].begin();
                    int del = it->id;
                    s[vis[a]].erase({it->t, it->cnt, it->id});
                    vis[del] = 0;
                    t[del] = 0;
                    if (change[del]) {
                        cout << 1 << ' ' << del << endl;
                        change[del] = 0;
                    }
                }
                s[vis[a]].insert({t[a], cnt[a], a});
                cout << 0 << ' ' << a << endl;
                change[a] = 1;
            }
        }
    }
}