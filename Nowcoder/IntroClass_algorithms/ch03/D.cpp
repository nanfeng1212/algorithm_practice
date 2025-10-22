#include<iostream>
#include<string.h>
using namespace std;
int n;
int c[100010],a[100010];
bool judge(int x)
{
    memset(a,0,sizeof(a));
    for(int i=1;i<x;i++)a[n-c[i]]++;
    for(int i=1;i<x;i++)
    {
        a[i]+=a[i-1];
        if(a[i]>=i)
            return false;
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(judge(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<n-l+1;
    return 0;
}