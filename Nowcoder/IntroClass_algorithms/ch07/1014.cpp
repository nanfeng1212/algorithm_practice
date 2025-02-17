#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n;
typedef long long ll;
ll f[40][200]={1};
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=4*i;j++)
            for(int k=1;k<=4;k++)
                if(j-k>=0){
                    f[i][j]+=f[i-1][j-k];}
    ll sum=((ll)1<<(n<<1));
    ll ans=0;
    for(int i=3*n;i<=4*n;i++)
        ans+=f[n][i];
    int p=gcd(ans,sum);
    cout<<ans/p<<"/"<<sum/p;
    return 0;
    
}
