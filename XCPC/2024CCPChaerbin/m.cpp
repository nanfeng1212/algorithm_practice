#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long>v;
        for(int i=1;i*i<=n;i++)
            if(n%i==0){
                v.push_back(i);
                if(i!=n/i)v.push_back(n/i);
            }
        sort(v.begin(),v.end());
        long long ans = 1;
        for(int i=0;i<v.size()-1;i++)
            ans += (v[i+1]-v[i])*n/v[i];
        ans += (n-v[v.size()-1])*n/v[v.size()-1];
        cout << ans << endl;
    }
}