#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
char x;
int ph[110];
int f[110][70][70];
vector<int>st;
vector<int>num;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            if(x == 'H')
                ph[i] += (1<<(j-1));
        }
       // cout<<ph[i]<<endl;;
    }
    
    for(int i=0;i<(1<<m);i++)
    {
        //cout<<i;
        if((i&(i<<1))!=0)continue;
        if((i&(i<<2))!=0)continue;
        st.push_back(i);
        cnt=0;
        int t=i;
        while(t)
        {
            if(t&1)
                cnt++;
            t>>=1;
        }
        num.push_back(cnt);
       //cout<<i<<' ';
        //cout<<*(num.end()-1)<<endl;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<st.size();j++)
        {
            int cur=st[j];
            if(cur&ph[i])continue;
            //cout<<num[j]<<endl;
            for(int k=0;k<st.size();k++)
            {
                int near=st[k];
                if(near&cur)continue;
                for(int u=0;u<st.size();u++)
                {
                    int last =st[u];
                    if(last&near)continue;
                    if(last&cur)continue;
                    f[i][j][k]=max(f[i][j][k],f[i-1][k][u]+num[j]);
                    ans=max(ans,f[i][j][k]);
                    //cout<<ans<<" ";
                }
            }
        }
    }
    cout<<ans;
    return 0;
        
}