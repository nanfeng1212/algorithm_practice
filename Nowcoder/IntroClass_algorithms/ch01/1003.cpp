#include<iostream>
using namespace std;
int m,n;
int a[1010];
int v[1010];
int k=0;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(v[x]==1)continue;
        v[x]=1;
        a[++k]=x;
        if(k>m)v[a[k-m]]=0;
    }
    cout<<k;
    return 0;
}