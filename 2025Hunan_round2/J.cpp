#include<bits/stdc++.h>
using namespace std;

struct ty{
    int a;
    int b;
    double t;
    bool operator < (const ty x) const{
        return t > x.t;
    }
};
priority_queue<ty> heap;
vector<int> cur;
vector<double> x(100010);
vector<long long> v(100010);
vector<int> pre(100010), nex(100010);
vector<bool> vis(100040, false);
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        pre[i] = i - 1;
        nex[i] = i + 1;
    }
    nex[n-1] = -1;
    for (int i = 0; i < n - 1; ++i) {
        int j = i + 1;
        double dx = x[j] - x[i];
        long long dv = v[i] - v[j];
        if (dv > 0) {
            double t = dx/dv;
            heap.push({i,j,t});
        }
    }
    while (!heap.empty()) {
        auto [i,j,t] = heap.top();
        heap.pop();
        if (vis[i] || vis[j]) continue;
        vis[i] = true;
        vis[j] = true;
        int p = pre[i];
        int s = nex[j];
        if (p != -1) {
            nex[p] = s;
        }
        if (s != -1) {
            pre[s] = p;
        }
        if (p!=-1 && s!=-1) {
            double dx = x[s]-x[p];
            long long dv = v[p]-v[s];
            if (dv > 0) {
                double t_new = dx/dv;
                heap.push({p, s, t_new});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cur.push_back(i + 1);
        }
    }
    cout << cur.size() << "\n";
    for (auto idx : cur) {
        cout << idx << " ";
    }
    return 0;
}