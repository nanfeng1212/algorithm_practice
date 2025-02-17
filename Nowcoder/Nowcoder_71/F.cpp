#include<bits/stdc++.h>
#define ll long long
#define MO 1000000007ll
#define MXN 1000002
using namespace std;
inline void rd(ll &x){x=0;short f=1;char c=getchar();while((c<'0'||c>'9')&&c!='-') c=getchar();if(c=='-') f=-1,c=getchar();while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();x*=f;}

ll T=1,n,m,k,a[MXN],ans;
ll p[32];
ll ksm(ll a,ll b){
    ll s=1;
    while(b){
        if(b&1) s*=a,s%=MO;
        a*=a,a%=MO;
        b>>=1;
    }
    return s;
}
ll cal(ll n,ll m){//求组合数
    ll ans=1;
    for(ll i=1,j=n-m+1;i<=m;i++,j++)
        ans*=j*ksm(i,MO-2)%MO,ans%=MO;
    return ans;
}
void solve(){
    rd(n),rd(m),rd(k);
    for(ll i=0;i<=30;i++)
        p[i]=cal(k,i)*ksm(ksm(2,k),MO-2)%MO,
        p[31]+=MO-p[i];
    p[31]=(1+p[31])%MO;
    for(ll i=1,x;i<=n;i++){
        rd(x);
        for(ll j=0;j<=31;j++){
            ans+=x*p[j]%MO,ans%=MO;
            x+=x&m;
        }
    }
    cout << ans << endl;
}int main(){while(T--) solve();}