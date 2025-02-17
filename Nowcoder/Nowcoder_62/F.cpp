#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N],b[N],n,m,root[N],cnt;
struct node{int l,r,sum;}tr[N<<5];
void update(int &p,int pr,int l,int r,int v)
{
    p=++cnt;
    tr[p]=tr[pr],tr[p].sum++;
    int mid=(l+r)>>1;
    if(l<r)
    {
        if (v <= mid) update(tr[p].l, tr[pr].l, l, mid, v);
        else update(tr[p].r, tr[pr].r, mid + 1, r, v);
    }
}
int query(int p,int pr,int l,int r,int k)
{
    if(l==r) return l;
    int sum=tr[tr[p].l].sum-tr[tr[pr].l].sum;
    int mid=(l+r)>>1;
    if(sum>=k) return query(tr[p].l,tr[pr].l,l,mid,k);
    else return query(tr[p].r,tr[pr].r,mid+1,r,k-sum);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    int size= unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++)
    {
        int x= lower_bound(b+1,b+1+size,a[i])-b;
        update(root[i],root[i-1],1,size,x);
    }
    while(m--)
    {
        int l,r,k;
        cin>>l>>r;
        k=(r-l+1)/2+1;
        int t=query(root[r],root[l-1],1,size,k);
        cout<<b[t]<<endl;
    }
}