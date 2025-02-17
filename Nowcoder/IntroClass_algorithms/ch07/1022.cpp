#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int f[3610];
int t,n;
int a[100010];
int v[10000];
int main()
{
    cin >> t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        cin >> n;
        for(int i = 1; i <= n; i++ )
            cin >> a[i];
        if(n>=3600){
            cout<<"YES\n";
            continue;
        }
        for(int i=1;i<=n&&!f[0];i++)
        {
            int cnt=0;
            for(int j=1;j<3600;j++)
            {
                if(f[j])
                    v[cnt++]=(j+a[i])%3600;
            }
            for(int j=0;j<cnt;j++)
            {
                f[v[j]]=1;
            }
            f[a[i]%3600]=1;
        }
        if(f[0])cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}