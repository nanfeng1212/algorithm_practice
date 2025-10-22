#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010];
vector<int>v;
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        int sum=0;
        int ans=-1e9;
        v.clear();
        cin>>n;
        cin>>a[1];
        sum+=a[1];
        v.push_back(sum);

        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            if(abs(a[i])%2!=abs(a[i-1])%2&&sum>=0)
            {
                sum+=a[i];
                v.push_back(sum);
            }
            else{
                v.push_back(sum);
                sum=a[i];
                v.push_back(sum);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            //cout<<ans<<' '<<v[i]<<endl;
            ans=max(ans,v[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
