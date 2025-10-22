
/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
struct ty {
    int d;
    int u;
    int r;
};
int p[410];
vector<ty>user;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int r,m;
        cin >> r >> m;
        for (int j=1; j<=r; j++) {
            int k;
            cin >> k;
            p[k] = i;
        }
        set<int>ans;
        map<pair<int,int>,int>mp1;
        while (m--) {
            int d,u,r;
            cin >> d >> u >> r;
            d++;
            if (mp1.find({d,u})!=mp1.end())continue;
            user.push_back({d,u,r});
        }
        for(int j=0; j<user.size(); j++) {
            int dt = user[j].d;
            int rt = user[j].r;
            if (!p[rt])continue;
            if (dt<p[rt]+7&&dt>=p[rt]&&i<p[rt]+7&&i>=p[rt])
                ans.insert(user[j].u);
        }
        cout << i-1;
        if (ans.size())
            for (auto j:ans)cout << ' ' << j;
        cout << endl;
    }
}
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,r;
struct ty{
    int d,u,p;
};
vector<ty> v[1010];
map<int,pair<int,int>> pos;
map<int,bool> st;
 
void setf(int p,int d){
    if(!st[p]) pos[p]={d,d+6};
    else {
        if(d<=pos[p].second+1) pos[p].second=d+6;
        else pos[p]={d,d+6};
    }
    st[p]=true;
}
 
bool check(int d1,int u,int p,int d) {
    if(st[p]&&d1>=d-6&&d1<=d&&d1>=pos[p].first&&d<=pos[p].second)
        return true;
    return false;
}
 
int main(){
    cin>>n;
    for(int h=0; h<n; h++){
        cin >> r >> m;
        for(int i=1; i<=r; i++){
            int t;
            cin >> t;
            setf(t,h);
        }
        for(int i=1; i<=m; i++){
            int d,u,p;
            cin >> d >> u >> p;
            if(d<=h) v[h].push_back({d,u,p});
        }
        set<int> ans;
        for(int i=(h-6>=0?h-6:0); i<=h; i++){
            for(int j=0; j<v[i].size(); j++){
                if(check(v[i][j].d, v[i][j].u, v[i][j].p, h))
                    ans.insert(v[i][j].u);
            }
        }
        cout << h;
        for(auto i:ans) cout<<" "<<i;
        cout << endl;
    }
}
