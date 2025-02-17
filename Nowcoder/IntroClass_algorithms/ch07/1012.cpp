#include<bits/stdc++.h>
using namespace std;
int a[30010];
int cnt=0;
int k[30010];
int f[30010];
int main()
{
    int n=1;
    while(cin>>a[n])
        n++;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
            if(a[i]<=a[j])
                f[i]=max(f[i],f[j]+1);
        int p=0;
        while(p<cnt&&a[i]>k[p])p++;
        if(p==cnt)k[cnt++]=a[i];
        else k[p]=a[i];
    }
    cout<<f[n]<<endl;
    cout<<cnt<<endl;
    return 0;
}