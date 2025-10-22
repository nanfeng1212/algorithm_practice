#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+10,mod=1e9+7;
int dp[N];
vector<int>f[N];
int qmi(int a,int k,int p)
{
	int res=1;
	while(k)
	{
		if(k&1)res=(res*a)%p;
		a=(a*a)%p;
		k>>=1;
	}
	return res;
}
int dfs(int u,int fa)
{
	for(auto v:f[u])
	{
		if(v==fa)continue;
	      if(u!=1)
		    dp[u]+=qmi(f[u].size()-1,mod-2,mod)*dfs(v,u)%mod;
		else
            dp[u]+=qmi(f[u].size(),mod-2,mod)*dfs(v,u)%mod;
	}
	dp[u]=(dp[u]+1)%mod;
    //cout<<u<<" "<<dp[u]<<endl;
	return dp[u];
}
signed main()
{
    int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		f[u].push_back(v);
		f[v].push_back(u);
	}
	cout<<dfs(1,-1)<<endl;
	return 0;
}