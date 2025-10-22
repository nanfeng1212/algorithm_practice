#include<bits/stdc++.h>
using namespace std;

vector<int> edge[100010];
int n,m;
int c[100010];
int cntc[100010];
int ans[100010];
int sz[100010];
int dfn[100010];
int dfn2[100010];
int big[100010];
int r[100010];
int cnt;
int tot;
void add(int u) {
  if (cntc[c[u]] == 0) ++cnt;
  cntc[c[u]]++;
}

void del(int u) {
  cntc[c[u]]--;
  if (cntc[c[u]] == 0) --cnt;
}

int getAns() { return cnt; }

void dfs(int x, int pa){
    sz[x] = 1;
    tot++;
    dfn[x] = tot;
    dfn2[tot] = x;
    for(int i = 0; i < edge[x].size(); i++){
        int y = edge[x][i];
        if(y != pa){
            dfs(y,x);
            sz[x] += sz[y];
            if(!big[x] || sz[y] > sz[big[x]])
                big[x] = y;
        }
    }
    r[x] = tot;
}

void dfs1(int x, int pa, int flag){
    for(int i = 0; i < edge[x].size(); i++){
        int y = edge[x][i];
        if(y!=pa && y!=big[x]){
            dfs1(y, x, 0);
        }
    }
    if(big[x])dfs1(big[x], x, 1);
    for(int i = 0; i < edge[x].size(); i++){
        int y = edge[x][i];
        if(y!=pa && y!=big[x]){
            for(int j = dfn[y]; j <= r[y]; j++){
                add(dfn2[j]);
            }
        }
    }
    add(x);
    ans[x] = cnt;
    if(!flag){
        for(int j = dfn[x]; j <= r[x]; j++){
            del(dfn2[j]);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    dfs1(1,0,0);
    
    cin >> m;
    while(m--){
        int k;
        cin >> k;
        cout << ans[k] << endl;
    }
    return 0;
}