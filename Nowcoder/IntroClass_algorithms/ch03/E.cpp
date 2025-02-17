#include<iostream>
#include<string.h>
using namespace std;
int n,d,h[50510];
long long a[50010];
bool fun(long long x)
{
    long long sum=0;
    int i=1;
    for(int j=1;j<=d;j++)
    {
        sum>>=1;
        while(sum<x&&i<=n)
        {
            a[i]=j;
            sum+=h[i++];
        }
    }
    if(i<=n)for(;i<=n;i++)a[i]=d;
    return sum>=x;
}
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    long long l=0,r=5e10,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(fun(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l-1<<endl;
    fun(l-1);
    for(int i=1;i<=n;i++)cout<<a[i]<<endl;
    return 0;
    
    
    
    
}