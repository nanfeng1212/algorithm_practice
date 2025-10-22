#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>n>>q;
        for(int i=1;i<n;i++)
            cout<<i<<' '<<i+1<<endl;
        int first = 2;
        for(int i=1;i<=q;i++)
        {
            int x;
            cin>>x;
            if(x==n-first+1)
                cout<<-1<<' '<<-1<<' '<<-1<<endl;
            else{
                int second = n-x+1;
                cout<<1<<' '<<first<<' '<<second<<endl;
                first = second;
            }
        }
    }
    return 0;
}
