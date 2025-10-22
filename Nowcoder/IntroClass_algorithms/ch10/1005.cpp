#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll prime[10000000];
int cnt=0;
ll v[30000010];
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=i;
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++)
        {
            if(prime[j]>i||prime[j]*i>n)break;
            v[prime[j]*i]=prime[j];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=v[i];
    cout<<ans<<endl;
}