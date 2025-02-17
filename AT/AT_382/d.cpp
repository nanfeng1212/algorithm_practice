#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>res;
vector<int>ans;

void dfs(int x){
    if(x+10*(n-ans.size())>m)return;
    if(ans.size()==n){
        res.push_back(ans);     
        return;
    }
    for(int i=x+10;i<=m;i++){
        ans.push_back(i);
        dfs(i);
        ans.pop_back();
    }

}
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        ans.clear();
        if(i+10*(n-1)>m)
            break;
        ans.push_back(i);
        dfs(i);
    }
    cout << res.size()  << endl;
    for(auto i:res){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
    
}