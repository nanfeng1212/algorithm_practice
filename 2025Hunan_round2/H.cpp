#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
struct ty{
    vector<vector<ll>> arr;
    vector<vector<ll>> dep;
    void fun(vector<int>t, vector<int>d) {
        arr.resize(n + 1, vector<ll>(n + 1));
        dep.resize(n + 1, vector<ll>(n + 1));
        for(int s=1; s<=n; s++) {
            ll cur_t = 0;
            int cur = s;
            for(int i=0; i<n; i++) {
                int k = cur;
                arr[s][k] = cur_t;
                dep[s][k] = cur_t+t[k];
                cur_t += t[k]+d[k];
                cur = (cur==n) ? 1:cur+1;
            }
        }
    }
};

set<int>ab[410];
set<int>ac[410];
set<int>bc[410];
int main() {
    cin >> n;
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> d[i];
    vector<int> t_t(n + 1), t_a(n + 1), t_i(n + 1);
    for(int i=1; i<=n; i++) cin >> t_t[i];
    for(int i=1; i<=n; i++) cin >> t_a[i];
    for(int i=1; i<=n; i++) cin >> t_i[i];
    ty T,A,I; 
    T.fun(t_t, d);
    A.fun(t_a, d);
    I.fun(t_i, d);
    for(int a=1; a<=n; a++) {
        for(int b=1; b<=n; b++) {
            if(a==b) continue;
            bool flag1 = true;
            for(int k=1; k<=n; k++) {
                if(T.arr[a][k]<A.dep[b][k] && A.arr[b][k]<T.dep[a][k]) {
                    flag1 = false;
                    break;
                }
            }
            if(flag1) ab[a].insert(b);
        }

        for(int c=1; c<=n; c++) {
            if(a==c) continue;
            bool flag2 = true;
            for(int k=1; k<=n; k++) {
                if(T.arr[a][k]<I.dep[c][k] && I.arr[c][k]<T.dep[a][k]) {
                    flag2 = false;
                    break;
                }
            }
            if(flag2) ac[a].insert(c);
        }
    }
    for(int b=1; b<=n; b++) {
        for(int c=1; c<=n; c++) {
            if(c==b) continue;
            bool flag1 = true;
            for(int k=1; k<=n; k++) {
                if(A.arr[b][k]<I.dep[c][k] && I.arr[c][k]<A.dep[b][k]) {
                    flag1 = false;
                    break;
                }
            }
            if(flag1) bc[b].insert(c);
        }
    }

    for(int i=1; i<=n; i++) {
        if (ab[i].size()==0)continue;
        int a = i;
        for(auto b:ab[i]) {
            set<int>bb;
            set_intersection(ac[a].begin(), ac[a].end(), bc[b].begin(), bc[b].end(),inserter(bb, bb.begin()));
            if(bb.size()){
                cout << a << ' ' << b << ' ' << *bb.begin();
                return 0;
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}