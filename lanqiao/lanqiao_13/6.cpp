#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 998244353;
ll ksm(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = res*a%mod;
        }
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
int n;
ll x;
int fa[100010];
int find(int x){
    return fa[x] == x?x:fa[x] = find(fa[x]);
}
ll h[100010],a[100010],s[100010];
bool check(int y){
    memset(s,0,sizeof(s));
    s[0] = 2*x;
    for(int i=0;i<=n;i++)fa[i] = i;
    for(int i=1;i<n;i++)a[i] = h[i];

    for(int i=0;i<n;i++){
        int to = i+y;
        if(to>=n){
            s[n]+=s[i];
            continue;    
        }
        else{
            while(1){
                int ms = min(a[to],s[i]);
                s[i] -= ms;
                s[to] += ms;
                a[to]-=ms;
                if(a[to]==0)fa[to]=to-1;
                if(s[i]==0)break;
                to = find(to-1);
                if(to<=i)break;
            }
        }
    }
    return s[n]==2*x;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> x;
    for(int i=1;i<n;i++){
        cin >> h[i];
    }
    int l=1,r=n;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid-1;
        }   
        else{
            l = mid+1;
        } 
    }
    cout << r+1 << endl;
    return 0;
 
}