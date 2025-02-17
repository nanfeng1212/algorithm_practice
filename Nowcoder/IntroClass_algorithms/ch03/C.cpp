#include<iostream>
using namespace std;
int n,m;
long long L;
long long a[50010];
long long d[50010];
bool judge(long long x)
{
    int k=0;
    for(int i=1;i<=n+1;i++)
        d[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)
    {
        if(d[i]<x){
           // cout<<i<<endl;
            d[i+1]+=d[i];
            d[i]=0;
            k++;
        }
    }
   int i=n;
    while(d[n+1]<x&&i>=1)
    {
        if(d[i]!=0)
        {
            d[n+1]+=d[i];
            d[i]=0;
            k++;
        }            
        i--;
    }
    return k<=m;
}
    

int main()
{
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=L;
    long long l=0,r=L,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(judge(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l-1;
    return 0;
    
}