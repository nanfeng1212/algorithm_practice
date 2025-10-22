#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
unordered_map<ll,ll>fa;
ll find(ll x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(ll x,ll y)
{
    fa[find(x)]=find(y);
}
int main()
{
    cin>>n>>q;
    ll res=q;
    for(ll i=1;i<=q;i++)
    {
        int x,y;
        string s;
        cin>>x>>y>>s;
        if(fa.count(x-1)==0)fa[x-1]=x-1,fa[x-1+n+1]=x-1+n+1;
        if(fa.count(y)==0)fa[y]=y,fa[y+n+1]=y+n+1;
        if(s=="even"){
            if(find(x-1)==find(y+n+1)){
                res=i-1;
                break;
            }
            else{
                merge(x-1,y);
                merge(x-1+n+1,y+n+1);
            }
            
        }
        else{
            if(find(x-1)==find(y))
            {
                res=i-1;
                break;
            }
            else{
                merge(x-1,y+n+1);
                merge(x-1+n+1,y);
            }
        }
    }
    cout<<res;
    return 0;
}