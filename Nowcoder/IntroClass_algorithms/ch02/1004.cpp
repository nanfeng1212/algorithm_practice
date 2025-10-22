#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct ty{
    int x;
    int y;
}a[5010];
bool cmp(ty a,ty b)
{
    if(a.y!=b.y)
        return a.y>b.y;
    else return a.x<b.x;
}
int main()
{
    scanf("%d%d",&n,&m);
    int k=m*1.5;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    int s=a[k].y;
    int l=k+1;
    while(a[l].y==s)
    {
        l++;k++;
    }
    cout<<s<<' '<<k<<endl;
    for(int i=1;i<=k;i++)
        cout<<a[i].x<<" "<<a[i].y<<endl;
    return 0;
}