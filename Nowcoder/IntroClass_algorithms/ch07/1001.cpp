#include<bits/stdc++.h>
using namespace std;
long long f[100];
long long fun(int x)
{
    if(f[x]!=0)return f[x];
    else{
        if(x==0)return 1;
        if(x==1)return 1;
        else return (f[x]=fun(x-1)+fun(x-2));
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {    
    
        int n;
        cin>>n;
        cout<<fun(n)<<endl;
    }
    return 0;
}