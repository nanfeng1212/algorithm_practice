#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long k;
long long l[200010];
bool judge(long long x)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=l[i]/x;
    return sum>=k;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>l[i];
    sort(l+1,l+n);
    long long l1=1,r=1e9;
    while(l1<=r){
        long long mid=(l1+r)>>1;
        if(judge(mid))l1=mid+1;
        else r=mid-1;
    }
    cout<<l1-1;
    return 0;
}