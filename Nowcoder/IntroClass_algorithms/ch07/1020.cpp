#include<bits/stdc++.h>
using namespace std;
int n;
int a[110];
int main()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int k=sum/2;
    int f[10010];
    f[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=k;j>=a[i];j--)
            f[j]=max(f[j],f[j-a[i]]+a[i]);
    int ans = 0;
    for( int i = 1; i <= sum; i++ )
        ans = max(ans,f[i]);
    cout << ans << ' ' << sum-ans << endl;
    return 0;
    
}