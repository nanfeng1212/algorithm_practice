#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
#define alls(x) x.begin(),x.end()
#define vi vector<int>

void solve()
{
    int n,k;
    cin >> n >> k;
    vi a(n),b(n);
    for(auto &x:a)cin >> x;
    for(auto &x:b)cin >> x;
    vi ans(n);
    for(int i = 0; i < n; i++)
    {
        int u = a[i]/b[i];
        ans[i] = u;
    }
    ll s = 0;
    for(int i = 0; i < n; i++)
    {
        s +=ans[i];
    }
    if(s<k)
    {
        for(int i = 0; i < n; i++)
            cout<<0<<" ";
    }
    else
    {
        for(auto &x:ans){
            if(s>k){
                int res = s-k;
                if(x>=res){
                    x-=res;
                    s = k;
                }
                else{
                    res = res-x;
                    s -= x;
                    x = 0;
                }
            }
            else break;
        }
        for(auto &x:ans)
            cout<<x<<" ";
    }
    cout<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while(_--)solve();
}