#include<iostream>
using namespace std;
int n;
long long m;
long long c[55];
bool judge(long long x)
{
    long long  sum=0;
    for(int i=1;i<=n;i++)
        if(x>c[i])sum+=x-c[i];
    if(sum>x||sum>m)return false;
    else return true;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    long long  l=0,r=5e9;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(judge(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l-1;
    return 0;
}