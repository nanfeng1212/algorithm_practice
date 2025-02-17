/*
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
 
int n,k;
int a[100010];
vector<int>dp1(100010);
vector<int>dp2(100010);
int vis1[100010];
int vis2[100010];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    int cnt = 0;
    dp1[0] = 0;
    for(int i=1;i<=n;i++){
        if(cnt == 0){
            dp1[++cnt] = a[i];
            vis1[i] = cnt;
        }
        else{
            if(dp1[cnt]<=a[i]){
                dp1[++cnt] = a[i];
                vis1[i] = cnt;
            }
            else{
                int pos = upper_bound(dp1.begin(),dp1.begin()+cnt,a[i])-dp1.begin();
                vis1[i] = pos;
                dp1[pos]=a[i];
            }
        }
    }
    cnt = 0;
    for(int i=n;i>=1;i--){
        if(cnt==0){
            dp2[++cnt] = a[i];
            vis2[i] = cnt;
        }
        else{
            if(a[i]<=dp2[cnt]){
                dp2[++cnt]=a[i];
                vis2[i] = cnt;
            }
            else{
                int l=1,r=cnt;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(dp2[mid]>=a[i]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                vis2[i] = l;
                dp2[l]=a[i];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=n-k;i++){
        int l = a[i],r=0;
        int res1 = vis1[i],res2=0;
        if(i+k+1<=n){
            r = a[i+k+1];
            res2 = vis2[i+k+1];
        }
        int res = 0;
        if(l<=r){
            res =res1+res2+k;
        }
        else{
            res = max(res1+k,res2+k);
        }
        ans = max(ans,res);
    }
    cout << ans << endl;
    return 0;
  
}
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
using namespace std;
int n,k,m,ans;
int a[N],s[N],f[N],tr[N],g[N];
int qmax(int x)
{
    int ans=0;
    for(;x;x-=x&-x)
        ans=max(ans,tr[x]);
    return ans;
}
void add(int x,int y){
    for(;x<=n;x+=x&-x) 
        tr[x]=max(tr[x],y);
}
int main()
{
    memset(tr,0,sizeof(tr));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]),s[i]=a[i];
    sort(s+1,s+n+1);
    m=unique(s+1,s+n+1)-s-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(s+1,s+m+1,a[i])-s;
    for(int i=1;i<=n;i++)
        f[i]=qmax(a[i])+1,add(a[i],f[i]);
    memset(tr,0,sizeof(tr));
    for(int i=n;i>=1;i--)
        g[i]=qmax(n-a[i]+1)+1,add(n-a[i]+1,g[i]);
    memset(tr,0,sizeof(tr));
    a[n+1]=m+1;
    for(int i=k+2;i<=n+1;i++)
    {
        add(a[i-k-1],f[i-k-1]);
        ans=max(ans,k+g[i]+qmax(a[i]));
    }
    printf("%d\n",ans);
    return 0;
}