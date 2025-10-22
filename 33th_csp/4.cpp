#include<bits/stdc++.h>
using namespace std;

int c, m, n;
map<int,int> mp;
int vis[300010];
unordered_map<int,int> idx; 
struct nodes{
    int l;
    int r;
    int w;
}dp[300010];

void change(int p){ 
    if(dp[p].l > 0){
        dp[dp[p].l].w += 1;
        dp[dp[p].l].r = dp[p].r;
    }
    if(dp[p].r <= m){
        dp[dp[p].r].w += 1;
        dp[dp[p].r].l = dp[p].l;
    }
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(),cout.tie();
    cin >> c >> m >> n;
    for(int i=1; i <=m; i++) {
        int x, w; 
        cin >> x >> w;
        mp[x] = w;
    }
    int cnt = 1;
    for(auto &t: mp){
        dp[cnt].w = t.second;
        dp[cnt].l = cnt - 1;
        dp[cnt].r = cnt + 1;
        idx[t.first] = cnt;
        cnt++;
    }
    int ans = m;
    while (n--) {
        int p;
        cin >> p;
        p = idx[p];
        dp[p].w++;
        if (dp[p].w>=5) { 
            change(p);
            ans--;
            priority_queue<int, vector<int>, greater<int>> q;
            if(dp[dp[p].l].w>=5 && !vis[dp[p].l]) 
                q.push(dp[p].l), vis[dp[p].l] = true;
            if(dp[dp[p].r].w>=5 && !vis[dp[p].r]) q.push(dp[p].r), vis[dp[p].r] = true;
            while (!q.empty()) {
                int t = q.top();
                q.pop();
                change(t);
                ans--;
                if(dp[dp[t].l].w>=5 && !vis[dp[t].l]) q.push(dp[t].l), vis[dp[t].l] = true;
                if(dp[dp[t].r].w>=5 && !vis[dp[t].r]) q.push(dp[t].r), vis[dp[t].r] = true;
            }

        }
        cout << ans << endl;
    }
    return 0;
}
