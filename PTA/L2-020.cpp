#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>e[100010];
int v[100010];
double ans = 0.0;
double q[100010];
double z;
void bfs(int x, int l) {
    if (!e[x].size()) {
        ans += z*q[l]*v[x];
        //cout << x << ' ' << z << ' ' << q[l] << ' ' << v[x] << endl;       
        return ;
    }
    for (auto i:e[x]) {
        bfs(i,l+1);
    }
}
int main(){
    int n;
    cin >> n;
    cin >> z;
    double r;
    cin >> r;
    double c = 1.0-r/100.0;
    q[0] = 1;
    for (int i=1; i<n; i++) {
        q[i] = q[i-1]*c;
    }
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        if (!k) {
            cin >> v[i];
        }
        while (k--) {
            int p;
            cin >> p;
            e[i].push_back(p);
        }
    }
    bfs(0,0);
    cout << ll(ans) << endl;
}