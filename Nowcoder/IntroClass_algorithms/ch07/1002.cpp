#include<bits/stdc++.h>
using namespace std;
int n,t;
const long long mod=1e9+7;
long long a[100010];
typedef long long ll;
int fun(int x)
{
    if(a[x]!=0)return a[x];
    else{
        if(x==0)return (ll)1;
        if(x==1)return (ll)3;
        if(x==2)return (ll)9;
        return (a[x]=((2*fun(x-1))%mod+(2*fun(x-2))%mod)%mod);
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fun(n)<<endl;
    }
    return 0;
}