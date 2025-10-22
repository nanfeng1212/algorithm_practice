#include<bits/stdc++.h>
using namespace std;

vector<int>e[10010];
int in[10010];
int pre[10010];
int ans = 0;
int res;
queue<pair<int,int>>q;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int p;
            cin >> p;
            e[i].push_back(p);
            pre[p] = i;
            in[p]++;
        }
        sort(e[i].begin(),e[i].end());
    }
    int r;
    for (int i=0; i<n; i++) {
        if (in[i]==0) {
            r=i;
            break;
        }
    }
    while(!q.empty()) q.pop();
    q.push({r,1});
    while(!q.empty()) {
        int x = q.front().first;
        int dep = q.front().second;
        q.pop();
        if (dep>ans)ans=dep,res=x;
        for(auto i:e[x]) {
            q.push({i,dep+1});
        }
    }
    vector<int>v;
    while (res!=r) {
        v.push_back(res);
        res = pre[res];
    }
    cout << ans << endl;
    cout << r;
    for (int i=v.size()-1; i>=0; i--) {
        cout << ' ' << v[i];
    }
}