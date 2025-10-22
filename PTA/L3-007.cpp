#include<bits/stdc++.h>
using namespace std;

struct node{
    int e;
    int w;
    int t;
    node (int a,int b,int c):e(a), w(b), t(c){}
};
vector<node> mp[505];
int n,m,s,t,inf=1e8, dis1,dis2;
int mpe[505][505];
string ans1, ans2;

void dfs(int a, int pre[], string &ss){
    if(a==s){
        ss = to_string(a);
        return ;
    }
    dfs(pre[a], pre, ss);
    ss +=" => "+to_string(a);
}
void dij1(){
    int dis[505], f[505],pre[505];
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(f,0,sizeof(f));
    for(int i=0; i<n; i++) 
        pre[i]=i;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;
    dis[s]=0;
    q.push({0,s});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int u = p.second;
        if (dis[u]<p.first)
            continue;
        for (auto i:mp[u]){
            int e = i.e;
            int w = i.w;
            if (dis[e]>dis[u]+w) {
                dis[e] = dis[u]+w;
                q.push({dis[e], e});
                pre[e] = u;
                f[e] += w;
            }
            else if (dis[e]==dis[u]+w && f[e]>f[u]+w){
                f[e] = f[u]+w;
                pre[e] = u;
            }
        }
    }
    dfs(t,pre,ans1);
    dis1 = dis[t];
}
void dij2(){
    int dis[505], f[505],pre[505];
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(f,0,sizeof(f));
    for(int i=0; i<n; i++) 
        pre[i]=i;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;
    dis[s] = 0;
    q.push({0,s});
    while (!q.empty()){
        pair<int,int> p=q.top(); q.pop();
        int u = p.second;
        if(dis[u]<p.first) continue;
        for(auto i:mp[u]){
            int e = i.e;
            int t = i.t;
            if(dis[e]>dis[u]+t){
                dis[e]=dis[u]+t;
                q.push(pair<int,int>(dis[e], e));
                pre[e] = u;
                f[e] = f[u]+mpe[e][u];
            } else if(dis[e]==dis[u]+t&&f[e]>f[u]+mpe[e][u]){
                f[e]=f[u]+mpe[e][u];
                pre[e]=u;
            }
        }
    }
    dfs(t,pre,ans2);
    dis2=dis[t];
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, flag, dis, time;
        cin >> u >> v >> flag >> dis >> time;
        mp[u].push_back(node(v,dis,time));
        if(!flag) 
            mp[v].push_back(node(u,dis,time));
        mpe[u][v] = mpe[v][u] = dis;
    }
    cin >> s >> t;
    dij1();
    dij2();
    if(ans1==ans2){
        cout << "Time = " << dis2 << "; Distance = " << dis1 << ": " << ans1;
    } 
    else {
        cout << "Time = " << dis2 << ": " << ans2 <<endl;
        cout << "Distance = " << dis1 << ": " <<ans1<<endl;
    }
    return 0;
}
