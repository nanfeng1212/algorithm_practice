#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
    int x;
    ll n;
    cin>>x>>n;
    int m=1;
    while(m<=x)m<<=1;
    if(m>=n){
        ll cnt=0;
        for(int i=1;i<=n;++i){
            if(!((x^i)%i)||!((x^i)%x))++cnt;
        }
        cout<<cnt<<'\n';
        return;
    }
    ll cnt=0;
    for(int i=1;i<m;++i){
        if(!((x^i)%i)&&(x^i)%x)++cnt;
    }
    ll l=n^(n&(m-1)),r=l+m;
    cnt+=(l-1)/x;
    for(ll y=(l-1)/x*x+x;y<r;y+=x){
        if((x^y)<=n)++cnt;
    }
    cout<<cnt<<'\n';
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}