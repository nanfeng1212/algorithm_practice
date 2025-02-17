#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll l,r;
        cin >> l >> r;
        ll flag=-1;
        for(ll i=60;i>=0;i--)
            if(((l >> i) & 1) != ((r >> i) & 1)) {
                flag=i;
                break;
            }
        cout<<(((ll)1)<<(flag+1))-1<<endl;
    }
}