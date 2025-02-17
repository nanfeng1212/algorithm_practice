#include<bits/stdc++.h>

using namespace std;

int t,n;
int a[1010],b[1010],f[1010][1010];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset(f,0,sizeof(f));
        for( int i = 1; i <= n; i++)
            cin >> a[i];
        for( int i = 1; i <= n; i++)
            cin >> b[i];
        for(int i=1;i<=n;i++)
        {
            f[i][0] = f[i-1][0] + a[i]*b[i];
            f[0][i] = f[0][i-1] + a[n-i+1]*b[i];
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j+i<=n;j++)
            {
                f[i][j] = max(f[i-1][j] + a[i]*b[i+j], f[i][j-1] + a[n-j+1]*b[i+j]);
                if(i+j==n)ans = max(ans, f[i][j]);
            }
        cout << ans << endl;
    }
    return 0;
}