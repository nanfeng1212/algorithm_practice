#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;cin>>n>>m>>k;
        map<pair<int,int>,int>mp1;
        map<int,int>mp2;
        vector<int>to1[n+1],to2[n+1];
        for(int i=1;i<=m;i++)
        {
            int l,r;
            cin>>l>>r;
            to1[l].push_back(i);
            to2[r].push_back(i);
        }
        set<int>q;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(auto j:to1[i])
                q.insert(j);
            if(q.size()==0)num++;
            else if(q.size()==1)mp2[*q.begin()]++;
            else if(q.size()==2)mp1[{*q.begin(),*q.rbegin()}]++;
            for(auto j:to2[i])q.erase(j);
        }
        int ans=0,sum1=0,sum2=0;
        for(auto [x,y]:mp2)
        {
            if(sum1<y)
            {
                sum2=sum1;
                sum1=y;
            }
            else if(sum2<y)
                sum2=y;
        }
        ans=sum1+sum2;
        for(auto [x,y]:mp1)
            ans=max(ans,y+mp2[x.first]+mp2[x.second]);
        cout<<ans+num<<endl;
    }
    return 0;
}
