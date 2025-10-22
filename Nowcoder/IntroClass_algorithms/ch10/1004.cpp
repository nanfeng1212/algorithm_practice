#include<bits/stdc++.h>
using namespace std;
int prime[1010];
bool vis[1010];
int cnt[1010];
int main()
{
    for(int i=2;i<=1010;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            prime[i]=1;
            for(int j=i+i;j<=1010;j+=i)
                vis[j]=1;
        }
    }
    for(int i=1;i<=1010;i++)
    {
        cnt[i]=cnt[i-1]+prime[i];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<cnt[n]<<endl;
    }
    return 0;
}