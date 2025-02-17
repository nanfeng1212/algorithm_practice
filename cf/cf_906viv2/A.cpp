#include<bits/stdc++.h>
#include<map>
using namespace std;
int n;
int a[110];
map<int,int>mp;
int cnt=0;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(mp.find(a[i])==mp.end())
            {
                cnt++;
                mp[a[i]]=1;
            }
            else{
                mp[a[i]]++;
            }
        }
        if(cnt==1){
            cout<<"Yes"<<endl;
            continue;
        }
        if(cnt!=2){
            cout<<"No"<<endl;
            continue;
        }
        int flag=1;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(n%2==0&&it->second!=n/2){
                flag=0;
                break;
            }
            if(n%2==1&&abs(it->second-n/2)>1)
            {
                flag=0;
                break;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
