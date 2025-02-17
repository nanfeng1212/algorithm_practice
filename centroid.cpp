#pragma GCC optimize(2)
#include<cstdio>
#include<vector>
#include<string.h> //memset 在这个库里
#include<iostream>
#include<algorithm> //POJ 不支持万能头,只能手写
using namespace std;

const int N=2e5+1;

inline int read(){
    char ch=getchar();
    int f=1; 
    while(!isdigit(ch)){
        if(ch=='-') 
            f=-f; ch=getchar();
        }
	int x=0;
    while(isdigit(ch))
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,mini,minh,T;
int d[N];
vector<int> G[N];
void dfs(int dep,int fa) {
	d[dep]=0; int t=0;
	for(int i=0;i<G[dep].size();i++) {
		int v=G[dep][i];
        if(v==fa)continue;
		dfs(v,dep); 
        d[dep]+=d[v]+1; //d[i] 是子树大小（不含自己）,统计的时候要算儿子自己,所以 +1
		t=max(t,d[v]+1); //得到最大子树
	} 
    t=max(t,n-d[dep]-1); //和另一边的子树比较,得到最大子树
	if(t<mini||(t==mini && dep<minh)) 
        mini=t,minh=dep; //更新答案
}

int main(){
	T=read();
    while(T--) {
		n=read();
		for(int i=1;i<n;i++) {
			int u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u); //建图
		} 
        minh=1e9; mini=1e9;
        dfs(1,0); //搜索
		printf("%d %d\n",minh,mini); //答案
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++)
            G[i].erase(G[i].begin(),G[i].end()); //多组数据初始化
	}
	return 0;
}

