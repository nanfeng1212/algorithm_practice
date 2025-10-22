#include<bits/stdc++.h>
#include<map>
typedef long long ll;
const ll maxn=5000000000;
using namespace std;
int l,r;
ll sum=0;
ll a[200000];
 queue<ll>p;
int cnt=0;
void bfs()
{
    
    p.push(4);
    p.push(7);
    while(!p.empty())
    {
        ll temp=p.front();
        p.pop();
        cnt++;
        a[cnt]=temp;
        if(temp*10+4<=maxn)
            p.push(temp*10+4);
        if(temp*10+7<=maxn)
            p.push(temp*10+7);
    }
}
int main()
{
    cin>>l>>r;
    bfs();
    ll cur=l-1;
    for(int i=1;i<=cnt;i++)
    {
        if(a[i]>=l){
            if(a[i]<=r)
            {
                sum+=(ll)(a[i]-cur)*a[i];
                cur=a[i];
            }
            else{
                sum+=(ll)(r-cur)*a[i];
                break;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}