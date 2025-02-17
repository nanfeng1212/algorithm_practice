#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using ld=long double;
ld Heronformula(ld a,ld b,ld c){
    ld p=(a+b+c)/2;
    ld s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}
void solve(){
    int n;
    cin>>n;
    map<i64,i64>cnt;
    for(int i=1;i<=n;i++){
        i64 len,a;
        cin>>len>>a;
        cnt[len]+=a;
    }
    vector<i64>v;
    for(auto t:cnt){
        if(t.second>=2){
            v.push_back(t.first);
        }
    }
    sort(v.begin(),v.end(),greater<i64>());
    ld ans=-1;
    for(auto &t:cnt){
        t.second--;
        for(auto q:v){
            if(cnt[q]>=2&&2*q>t.first){
                ans=max(ans,Heronformula(t.first,q,q));
                break;
            }
            if(2*q<=t.first) break;
        }
        t.second++;
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}
