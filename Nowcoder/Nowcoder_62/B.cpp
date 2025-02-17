#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100010];
signed main()
{
    int n,x;
    cin>>n>>x;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int i=1;
    while(x&&i<=n){
        sum+=a[i];
        if(x<0){
            x+=a[i];
        }
        else{
            x-=a[i];
        }
        i++;
    }
    cout<<sum;
}