#include<bits/stdc++.h>
using namespace std;

int fa[510];
int vis[510];
struct ty{
    int a;
    int b;
}mp[5010];

int find(int x){
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        fa[i]=i;
    for(int i=0; i<m; i++){
        cin >> mp[i].a >> mp[i].b;
        int f1 = find(mp[i].a);
        int f2 = find(mp[i].b);
        fa[f1] = fa[f2];
    }
    int cnt=0;
    for(int i=0;i<n;i++) 
        if(fa[i]==i)
            cnt++;
    int k;
    cin >> k;
    for(int i=1; i<=k; i++){
        int id, cur = 0;
        cin >> id;
        vis[id] = 1;
        for(int j=0; j<n; j++)
            fa[j]=j;
        for(int j=0; j<m; j++){
            if(!vis[mp[j].a] && !vis[mp[j].b]){
                int f1 = find(mp[j].a);
                int f2 = find(mp[j].b);
                fa[f1] = fa[f2];
            }
        }
        for(int j=0; j<n; j++)
            if(fa[j]==j && !vis[j])
                cur++;
        if(cur==cnt || cur+1==cnt)
            cout << "City " << id << " is lost.\n";
        else 
            cout << "Red Alert: City " << id << " is lost!\n";
        cnt = cur;
    }
    int sum = 0;
    for(int i=0; i<n; i++)
        if(vis[i]) sum++;
    if(sum==n)
        cout << "Game Over.\n";
}