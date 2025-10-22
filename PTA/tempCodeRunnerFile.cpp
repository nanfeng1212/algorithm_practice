#include<bits/stdc++.h>
using namespace std;

int vis[10010];
int prime[10010];
int p[10010];
int main() {
    for (int i=1; i<1010; i++) p[i] = 1;
    for (int i=2; i<1010; i++) {
        if (!vis[i])prime[++prime[0]] = i, p[i] = 2;
        for (int j=1; j<=prime[0]&&prime[j]*i<1010; j++) {
            vis[prime[j]*i] = 1;
            if (i%prime[j]==0) break;
        }
    }
    int l, r;
    cin >> l >> r;
    int depend[10001] = { 0 };
    map<int, int>mp;
    for (int i=l; i<=r; i++) {
        int t = i;
        vector<int> v;
        while (t!=1) {
            int sum = 0;
            while (t) {
                sum += (t%10)*(t%10);
                t /= 10;
            }
            t = sum;
            if (find(v.begin(), v.end(), t) != v.end()) break;
            v.push_back(t);
            depend[t] = 1;
        }
        if (t==1) mp[i] = v.size();
    }
    int flag = 0;
    for (auto [x,y] : mp)
        if (!depend[x]){
            flag = 1;
            cout << x << " " << p[x]*y << endl;
        }
    if (!flag) cout << "SAD" << endl;
    return 0;
}