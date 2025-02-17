#include<bits/stdc++.h>
#define ll long long
using namespace std;

int vis[200010];
int q[200010];
int p[200010];
map<pair<int,int>,int>mp;
void solve(){
    int n,m,k;
    int ans = 0;
    memset(q,0,sizeof(q));
    memset(p,0,sizeof(p));
    memset(vis,0,sizeof(vis));
    mp.clear();
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        vis[a] = 1;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        if(vis[a]&&vis[b])ans++;
        else if(vis[a])q[b]++;
        else if(vis[b])q[a]++;
        else{
            if(a==b){
                p[a]++;
                q[a]++;
            }
            else{
                mp[{min(a,b),max(a,b)}]++;
            }
        }
    }
    vector<int>v;
    for(int i=1;i<=k;i++){
        if(q[i])v.push_back(q[i]);
    }
    sort(v.begin(),v.end());
    int res = 0;
    if(v.size()){
        if(v.size()>=2)res+=v[v.size()-1]+v[v.size()-2];
        else res+=v[0];
    }
    for(auto [x,y]:mp){
        int a = x.first,b = x.second;
        int cnt = q[a]+q[b];
        res = max(res,cnt+y);
    }
    cout << ans+res << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}