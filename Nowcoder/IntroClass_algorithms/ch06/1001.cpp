#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n=8;
int a[10];
int v[10];
void dfs(int dp)
{
    if(dp>n)
    {
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i])continue;
        a[dp]=i,v[i]=1;
        dfs(dp+1);
        a[dp]=0,v[i]=0;
    }
}
int main()
{
    dfs(1);
	return 0;
}