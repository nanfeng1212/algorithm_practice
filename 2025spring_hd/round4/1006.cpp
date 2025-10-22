#include<bits/stdc++.h>
using namespace std;
#define long long int
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[200010];
int a[200010];
void update(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt){ 
    if (l==r) {
        sum[rt]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    update(rt);
}
void modify(int l,int r,int rt,int p,int v){ 
    if (l==r) {
        sum[rt]=v;
        return;
    }
    int m=(l+r)>>1;
    if (p<=m) modify(lson,p,v);
    else modify(rson,p,v);
    update(rt);
}

int query(int l,int r,int rt,int nowl,int nowr) {
    if (nowl<=l && r<=nowr) return sum[rt];
    int ans=0;
    int m=(l+r)>>1;
    if (nowl<=m) ans+=query(lson,nowl,nowr);
    if (m<nowr) ans+=query(rson,nowl,nowr);
    return ans;
}

signed main(){
    int T;
    cin >> T;
    while (T--) {
        int n,q;
        cin >> n >> q;
        memset(a,0,sizeof a);
        memset(sum,0,sizeof sum);
        for (int i=1; i<=n; i++)cin >> a[i];
        build(1,n)
    }
}