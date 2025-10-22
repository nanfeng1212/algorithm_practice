#include<iostream>
#include<map>
#include<string.h>
using namespace std;
int n,m;
map<string,int>fa;
int a[20010];
int find(int x)
{
    return a[x]==x?x:a[x]=find(a[x]);
}
void merge(int x,int y)
{
    a[find(x)]=find(y);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin>>x;
        fa[x]=i;
        a[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int op;string x,y;
        cin>>op>>x>>y;
        if(op==1)merge(fa[x],fa[y]);
        else{
            if(find(fa[x])==find(fa[y]))cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}