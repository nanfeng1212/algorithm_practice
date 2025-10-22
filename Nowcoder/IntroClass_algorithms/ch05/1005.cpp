#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
priority_queue<ll,vector<ll>,less<ll>>p;
struct ty{
   ll t1,t2;  
}a[150010];
bool cmp(ty x,ty y)
{
    return x.t2<y.t2;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].t1>>a[i].t2;
    sort(a+1,a+1+n,cmp);
    ll k=a[1].t1;p.push(a[1].t1);
    ll ans=1;
    for(int i=2;i<=n;i++)
    {
        if(k+a[i].t1<a[i].t2)
        {
            k+=a[i].t1;
            p.push(a[i].t1);
            ans++;
        }
        else{
            if(a[i].t1<p.top())
            {
                k-=p.top();
                k+=a[i].t1;
                p.pop();
                p.push(a[i].t1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
    
}