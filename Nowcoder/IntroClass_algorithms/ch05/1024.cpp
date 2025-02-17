#include<bits/stdc++.h>
using namespace std;
int n,k;
int fa[150010];
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=3*n;i++)
        fa[i]=i;
    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        int d,x,y;
        cin>>d>>x>>y;
        if(x>n||y>n){
            cnt++;
            continue;
        }
        if(d==1)
        {
            if(find(x)==find(y+n)||find(x)==find(y+2*n))
                cnt++;
            else{
                merge(fa[x],fa[y]);
                merge(fa[x+n],fa[y+n]);
                merge(fa[x+2*n],fa[y+2*n]);
            }
        }
        else{
            if(find(x)==find(y)||find(x)==find(y+2*n))
                cnt++;
            else{
                merge(fa[x],fa[y+n]);
                merge(fa[x+n],fa[y+2*n]);
                merge(fa[x+2*n],fa[y]);
            }
        }
    }
    cout<<cnt;
    return 0;
}