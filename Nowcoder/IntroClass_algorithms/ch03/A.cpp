#include<iostream>
using namespace std;
long long n,q,t,b[50100];
bool fun(long long x)
{
    return b[x]>t;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        b[i]=c+b[i-1];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t;
        int l=1,r=n,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(fun(mid))r=mid-1;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}