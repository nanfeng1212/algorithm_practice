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
int fa[100010];
int find(int x){
    return fa[x] == x?x:fa[x] = find(fa[x]);
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    return 0;
 
}