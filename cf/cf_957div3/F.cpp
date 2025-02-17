#include<bits/stdc++.h>
using namespace std;

int n,x;
int a[100005];
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >>x;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(x%a[i]==0){
                if(mp[x/a[i]]){
                    ans++;
                    mp.clear();
                }else{
                    vector<int>res;
                    for (auto p : mp)
                    {
                        if(p.second==0)continue;
                        if(p.first*a[i]>x)continue;
                        res.push_back(p.first*a[i]);
                    }
                    for(auto q:res){
                        mp[q]++;
                    }
                    res.clear();
                }
                mp[a[i]]++;
            }
    
        }
        cout<<ans+1<<endl;
    }
}