#include<bits/stdc++.h>
using namespace std;
long long n;
const long long mod=1e9+7;
typedef long long ll;
ll ksc(ll x,ll y)
{
    ll res=0;
    while(x){
        if(x%2==1)
            res=(res+y)%mod;
        x>>=1;
        y=(y+y)%mod;
    }
    return res;
}
ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)res=ksc(res,x);
        x=ksc(x,x);
        y>>=1;
    }
    return res%mod;
}
int main()
{
    cin>>n;
    if(n==1)cout<<0<<endl;
    else if(n==2)cout<<1<<endl;
    else cout<<ksc(n,ksc(ksm(2,n-3),n-1))<<endl;
    return 0;
}