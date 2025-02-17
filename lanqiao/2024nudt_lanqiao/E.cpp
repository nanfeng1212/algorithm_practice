#include<bits/stdc++.h>
using namespace std;

vector<int>v[1000010];
int dep[1000010];
void dfs(int x){
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i]);
        q.push(dep[v[x][i]]);
    }
    if(q.empty()){
        dep[x] = 1;
        return ;
    }
    if(q.size()==1){
        dep[x] = q.top() + 1;
        return ;
    }
    while(q.size()>2){
        q.pop();
        int x = q.top()+1;
        q.pop();
        q.push(x);
    }
    q.pop();
    dep[x] = q.top()+1;
    q.pop();
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i<=n; i++){
            v[i].clear();
            dep[i]=0;
        }
        for(int i=2;i<=n;i++){
            int p;
            cin >> p;
            v[p].push_back(i);
        }
        dfs(1);
        cout << dep[1]-1 << endl;
    }
}