#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[1010];
int mp[1010][1010];
int a[1010];
int in[1010];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j];
            vis[a[j]]=1;
        }
        for(int j=a[1];j<=a[k];j++)
        {
            if(!vis[j])
            {
                for(int p=1;p<=k;p++)
                    if(mp[j][a[p]]==0)
                    {
                        mp[j][a[p]]=1;
                        vis[j]=1;
                        in[a[p]]++;
                    }
            }
        }
    }
    int ans=0;
    memset(vis,0,sizeof(vis));
    queue<int>q;
    /*for(int i=1; i<= n; i++)
    {
        if(!vis[i]&&in[i]==0)
        {
            q.push(i);
            vis[i]=1;
        }
    }
    */
    while(true)
    {    
        for(int i=1; i<= n; i++)
        {
            if(!vis[i]&&in[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
        if(q.empty())break;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            for(int j=1;j<=n;j++)
            {
                if(mp[i][j]){
                    mp[i][j]=0;
                    in[j]--;
                }
            }
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
