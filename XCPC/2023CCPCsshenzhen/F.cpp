#include<bits/stdc++.h>
using namespace std;
typedef long long ll;  
vector<int> v[100010];  
int du[100010],du1[100010];  
void solve(){
    int n;
    cin>>n;  
    for(int i=1;i<=n;i++){  
        int a,b;
        cin>>a>>b;  
        v[a].push_back(b);  
        v[b].push_back(a);  
        du[a]++,du[b]++;  
        du1[a]++,du1[b]++;  
    }  
    queue<int> q;  
    int sum=0;  
    set<int> S1;  
    for(int i=1;i<=n;i++){  
        if(du1[i]==1)
            q.push(i);                  
        if(du1[i]>=4)
            sum+=1;  
        if(du1[i]==5)
            S1.insert(i);  
    }  
    while(q.size()){  
        auto now=q.front();q.pop();  
        for(auto u:v[now]){  
            if(du1[u]==1)continue;  
            du1[u]--;  
            if(du1[u]==1)
                q.push(u);  
        }  
    }  
    set<int> S;  
    for(int i=1;i<=n;i++)
        if(du1[i]!=1)
            S.insert(i);  
    ll ans=0;  
    for(auto a:S){  
        for(auto b:v[a]){  
            if(S.count(b)==0)
                continue;  
            if(S1.size()-S1.count(a)-S1.count(b)!=0)
                continue;  
            ans+=n-sum;  
            if(du[a]==4)ans++;  
            if(du[b]==4)ans++;  
        }  
    }  
    cout<<ans/2<<endl;  
}  
int main() {    
    int T = 1;  
    //cin >> T;  
    while (T--) 
        solve();  
    return 0;  
}