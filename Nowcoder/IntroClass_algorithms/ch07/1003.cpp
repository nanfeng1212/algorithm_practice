#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll x)
{
    if(x==1)return 0;
    if(x==2)return 0;
    if(x&1)return fun(x/2)+fun(x/2+1)+1;
    else return 2*fun(x/2);
}
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fun(n)<<endl;
    }
    return 0;
}