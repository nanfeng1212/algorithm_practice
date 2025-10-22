#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,n,a[40];
    int f[20010]={0};
    cin>>v>>n;
    f[0]=1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=v;j>=a[i];j--)
            f[j]=(f[j]||f[j-a[i]]);
    int ans=0;
    for(int i=v;i>=0;i--)
        if(f[i]){ans=i;break;}
    cout<<v-ans<<endl;
    return 0;
}