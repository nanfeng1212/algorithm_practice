#include<bits/stdc++.h>

using namespace std;
int n;
long long c;
struct ty{
    int i;
    long long k;
};
long long a[200010];
bool cmp(ty x,ty y)
{
    return x.k>y.k;
}
vector<ty>v;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        cin>>a[1];
        v.clear();
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            v.push_back({i,a[i]-i*c});
        }
        sort(v.begin(),v.end(),cmp);
        int flag=1;
        long long sum=a[1];
        for(auto x:v)
        {
            //cout<<x.k<<' '<<x.i<<endl;
            if(x.k+sum>=0)sum+=a[x.i];
            else{
                flag=0;
                break;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}
