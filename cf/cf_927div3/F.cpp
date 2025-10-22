#include<bits/stdc++.h>
using namespace std;
int ans[1000010];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int>l(n+1);
        ans[0] = 0;
        vector<vector<int>>r(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            l[a]++;
            r[b].emplace_back(a);
        }
        multiset<int>cur;
        cur.clear();
        for(int i=1;i<=n;i++){
            ans[i] = ans[i-1];
            for(int j=0;j<l[i];j++){
                cur.insert(i);
            }
            //cout << cur.size() << endl;
            if(!cur.empty()){
                //cout << i <<' '<<*cur.begin()-1<<' '<<ans[*cur.begin()-1]+cur.size() << endl;
                ans[i] = max(ans[i],int(ans[*cur.begin()-1]+cur.size()));
            }
            for(auto j:r[i]){
                cur.erase(cur.find(j));
            }
        }
        cout << ans[n] << '\n';
        

    }
    return 0;
}