#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int>v[200010];
int b[200005];
int vis[200005];
int cnt = 0;
vector<int>ans[200010];
void dfs(int x){
	queue<int>q;
	vis[x] = 1;
	cnt++;
	q.push(x);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i=0; i<v[cur].size(); i++){
			if(vis[v[cur][i]])continue;
			ans[cur].push_back(v[cur][i]);
			vis[v[cur][i]] = 1;
			cnt++;
			if(!b[v[cur][i]])q.push(v[cur][i]);
		}
	}
	return;
}
int main(){
	int T = 1; 
    while(T--)
	{
		cin >> n >> m >> k;
		for(int i=1;i<=k;i++){
			int a;
			cin >> a;
			b[a] = 1;
		}
		for(int i=1;i<=m;i++){
			int p,q;
			cin >> p >> q;
			if(b[p] && b[q])continue;
			if(!b[p])v[p].push_back(q);
			if(!b[q])v[q].push_back(p);
		}
		/*if(k==n){
			cout << "No" << endl;
			return 0;
		}*/
		int s;
		for(s=1; s<=n; s++)
			if(v[s].size())
				break;
		dfs(s);
		if(cnt != n){
			cout << "No" << endl;
            return 0;
		}
		cout << "Yes" << endl;
		int res = 0;
		for(int i=1;i<=n;i++)
			if(ans[i].size())res++;
		cout << res << endl;
		queue<int>p;
		p.push(s);
		while(!p.empty()){
			int cur = p.front();
			p.pop();
			cout << cur << " " << ans[cur].size() << ' ';
			for(int i=0; i<ans[cur].size(); i++)
			{	
				cout << ans[cur][i] << ' ';
				if(ans[ans[cur][i]].size())p.push(ans[cur][i]);
			}
			cout << endl;
		}
	}
	return 0;
}
