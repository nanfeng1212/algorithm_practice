#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int prime[100000000];
int cnt=0;
int v[100000010];
int vis[100000010]={0};
int main()
{
    for(int i=2;i<=1e8;i++)
    {
        if(!v[i])
        {
            v[i]=i;
            prime[++cnt]=i;
            for(int j=1;j<=cnt;j++)
            {
                if (prime[j]*i>1e8) break;
                vis[prime[j]*i]=1;
            }
        }
        for(int j=1;j<=cnt;j++)
        {
            if(prime[j]>v[i]||prime[j]*i>1e8)break;
            v[prime[j]*i]=prime[j];
        }
    }
    for(int i=1;i<=1e8;i++)
        vis[i]+=vis[i-1];
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<vis[r]-vis[l-1]<<endl;
    }
    return 0;
}