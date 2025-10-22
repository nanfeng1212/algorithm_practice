#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
    int l,m;
    cin >>l >>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x]-=1;
        a[y+1]+=1;
    }
    int ans=0;
    int flag=0;
    for(int i=0;i<=l;i++)
    {
        flag+=a[i];
        if(flag==0)ans++;
    }
    cout << ans;
    return 0;
}