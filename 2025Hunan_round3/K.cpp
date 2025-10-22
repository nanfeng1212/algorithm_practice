#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define db double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define alls(x) x.begin()+1,x.end()
const int N = 100000+100;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;//998244353,1e9+7;
using namespace std;

void solve(){
    int n,e;
    cin >> n >> e;
    vector<int> cnt(30),vis(30);
    vector<string> s(n+1);
    for (int i = 1;i <= n;++i){
        string x;
        cin >> x;
        int num = 1;
        for (int j = 1;j < x.size();++j){
            if (x[j]!=x[0])break;
            if (x[j] == x[0]) num++;
        }
        if (num == x.size()) vis[x[0]-'a'] = 1;
        else cnt[x[0]-'a'] += num;
    }
    int minn = inf;
    int pos = -1;
    for (int i = 0;i < e;++i){
        if (vis[i]) continue;
        if (cnt[i]+1 < minn) {
            minn = min(minn, cnt[i] + 1);
            pos = i;
        }
    }
    if (pos == -1) cout << "NO" << '\n';
    else{
        for (int i = 0;i < minn;++i) cout << (char)(pos+'a');
    }
}

int main() {
    cout << fixed << setprecision(12);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}