#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ty{
  int v;
  ll w;
};
int n,m;
ll c[200010],d[200010];
vector<ty>e1[200010],e2[200010];
int ans = 0;
map<pair<int,int>,int>vis;
void dfs(int r1, int r2, int deep){
  ans = max(ans,deep);
  for (auto i : e1[r1]) {
    for (auto j:e2[r2]) {
      if(vis[{i.v,j.v}])continue;
      vis[{i.v,j.v}] = 1;
      if (i.w == j.w) {
        dfs(i.v,j.v,deep+1);
      }
    }
  }
}
int main()
{
  // 请在此输入您的代码
  cin >> n >> m;
  for (int i=1; i<=n; i++) cin >> c[i];
  for (int i=1; i<=m; i++) cin >> d[i];
  for (int i=1; i<n; i++) {
    int a,b;
    cin >> a >> b;
    e1[a].push_back({b,c[b]});
  }
  for (int i=1; i<n; i++) {
    int a,b;
    cin >> a >> b;
    e2[a].push_back({b,d[b]});
  }
  if (c[1]!=d[1]){
    cout << 0;
  }
  else {
    dfs(1,1,1);
    cout << ans;
  }
  return 0;
}