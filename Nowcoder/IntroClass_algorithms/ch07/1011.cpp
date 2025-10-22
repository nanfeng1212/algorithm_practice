#include<bits/stdc++.h>
using namespace std;
int n;
int a[110];
int f1[110];
int f2[110];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i-1;j++)
            if(a[i]>a[j])
                f1[i]=max(f1[i],f1[j]+1);
    for(int i=n;i>=1;i--)
        for(int j=n;j>i;j--)
            if(a[i]>a[j])
                f2[i]=max(f2[i],f2[j]+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,f1[i]+f2[i]);
    cout<<n-ans-1;
    return 0;
}