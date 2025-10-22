#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int root;
vector<int>ans;
int dep = 0;
vector<int>e[100010];
void dfs(int x, int d) {
    if (d>dep){
        dep = d;
        ans.clear();
        ans.push_back(x);
    }
    else if (d==dep) ans.push_back(x);
    for (auto i:e[x])
        dfs(i,d+1);
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) {
        int p;
        cin >> p;
        if (p==-1) root = i;
        else e[p].push_back(i);
    }
    dfs(root,1);
    cout << dep << endl;
    sort(ans.begin(),ans.end());
    cout << ans[0];
    for (int i=1; i<ans.size(); i++) cout << ' ' << ans[i]; 
}