#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10];
long long f[10][100][100];
vector<int>st;
vector<int>num;
int main()
{
    cin>>n>>k;
    for(int i = 0; i < (1<<n); i++)
    {
        if(i & (i<<1))continue;
        st.push_back(i);
        int t = i;
        int cnt = 0;
        while(t)
        {
            if(t & 1)cnt++;
            t >>= 1;
        }
        num.push_back(cnt);
    }
    //cout << st.size();
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
            for(int u = 0; u < st.size(); u++)
            {
                if(num[u] > j)continue;
                for(int m = 0; m < st.size(); m++)
                {
                    if(st[u] & st[m])continue;
                    if(st[u] & (st[m] << 1))continue;
                    if(st[u] & (st[m] >> 1))continue;
                    f[i][j][u] += f[i-1][j-num[u]][m];
                }
            }
    long long ans = 0;
    for(int i = 0; i < st.size(); i++)
    {
        ans += f[n][k][i];
    }
    cout << ans;
    return 0;
}