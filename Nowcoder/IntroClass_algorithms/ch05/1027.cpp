#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
ll h,r;
int fa[1010];
int f1[1010],f2[1010];
long long x[1010],y[1010],z[1010];
ll fun(ll x1,ll x2,ll y1,ll y2,ll z1,ll z2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>h>>r;
        for(int i=1;i<=n;i++)fa[i]=i;
        int totol1=0,totol2=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i]>>z[i];
            if(z[i]+r>=h){
                totol2++;
                f2[totol2]=i;
            }
            if(z[i]-r<=0)
            {
                totol1++;
                f1[totol1]=i;
            }
            for(int k=1;k<=i;k++)
            {
                if((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k])>4*r*r)continue;
                if (fun(x[i],x[k],y[i],y[k],z[i],z[k])<=4*r*r)
                    if(find(i)!=find(k))merge(i,k);
            }
        }
        bool flag=0;
        for(int i=1;i<=totol1;i++)
        {
            for(int j=1;j<=totol2;j++)
                if(find(f1[i])==find(f2[j]))
                {
                    flag=1;
                    break;
                }
            if(flag)break;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;    
    }
    return 0;
}