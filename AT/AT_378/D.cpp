#include<bits/stdc++.h>
using namespace std;
#define ll long long

char mp[20][20];
int h,w,k;
int ans = 0;
int vis[200];
int cnt = 0;
int a[4][2] = {1,0,-1,0,0,-1,0,1};
void dfs(int x, int y){
  if(cnt==k){
    ans++;
    return;
  }
  for(int i=0;i<4;i++){
    int nx = x + a[i][0];
    int ny = y + a[i][1];
    if(nx<1 || nx>h || ny<1 || ny>w || mp[nx][ny]=='#' || vis[nx*w+ny])continue;
    vis[nx*w+ny] = 1;
    cnt++;
    dfs(nx,ny);
    vis[nx*w+ny] = 0;
    cnt--;
  }
}
void solve(){
  cin >> h >> w >> k;
  for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)
      cin >> mp[i][j];
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(mp[i][j]=='.'){
        memset(vis,0,sizeof(vis));
        cnt = 0;
        vis[i*w+j] = 1;
        dfs(i,j);
      }
    }
  }
  cout << ans <<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
