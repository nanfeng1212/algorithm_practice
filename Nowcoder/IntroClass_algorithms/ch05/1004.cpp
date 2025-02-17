#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n;
struct ty{
    long long v,s;
}a[100010];
bool cmp(ty x,ty y)
{
    return x.s>y.s;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v>>a[i].s;
    }
    sort(a+1,a+1+n,cmp);
    priority_queue<int,vector<int>,greater<int>>p;
    long long sum=0,k=0;
    for(int i=1;i<=n;i++)
    {
        k+=a[i].v;
        p.push(a[i].v);
        while(p.size()>a[i].s)
        {
            k-=p.top();
            p.pop();
        }
        sum=max(sum,k);
    }
    cout<<sum;
    return 0;
}