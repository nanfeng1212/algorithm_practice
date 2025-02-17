#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];

int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll minn = 0x7f7f7f7f7f7f7f;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            minn = min(minn,a[i]);
        }
        int k;
        int flag = 1;
        for(int i=1;i<=n;i++)
            if(a[i]==minn)
            {
                k=i;
                break;
            }
        for(int i=k+1;i<=n;i++)
            if(a[i]<a[i-1])
            {
                flag=0;
                break;
            }
        if(flag)cout<<k-1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
