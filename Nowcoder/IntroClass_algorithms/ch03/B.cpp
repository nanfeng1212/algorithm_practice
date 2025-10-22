#include<iostream>
#include<algorithm>
const int  N=1e6+7;
using namespace std;
int a[N];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int len=0;
    for(int i=0;i*i<=1e9;i++)
        a[len++]=i*i;
    for(int i=0;i<n;i++)
    {
        int r,l;
        cin>>l>>r;
        cout<<upper_bound(a, a+len, r)-lower_bound(a, a+len, l)<<endl;
    }
    return 0;
}


