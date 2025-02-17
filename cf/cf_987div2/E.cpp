#include<bits/stdc++.h>
using namespace std;


vector<int>v[1000010];
int dep[1000010];
void dfs(int r){
    priority_queue<int,vector<int>,greater<int>>q;
    for(auto &i:v[r]){
        dfs(i);
        q.push(dep[i]);
    }
    if(q.empty()){
        dep[r] = 1;
        return ;
    }
    if(q.size()==1){
        dep[r] = q.top() + 1;
        return ;
    }
    while(q.size()>2){
        q.pop();
        int x = q.top()+1;
        q.pop();
        q.push(x);
    }
    q.pop();
    dep[r] = q.top() +1;
    q.pop();
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i<=n; i++)
            v[i].clear(), dep[i]=0;
        for(int i=2;i<=n;i++){
            int p;
            cin >> p;
            v[p].push_back(i);
        }
        dfs(1);
        cout << dep[1] - 1 << endl;
    }
}