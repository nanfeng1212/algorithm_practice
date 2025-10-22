#include <bits/stdc++.h>
using namespace std;
long long a[100010];
map<long long,long long>mp;
int main(){
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(mp.find(a[i]) == mp.end()){
            mp[a[i]]++;
            cout << ans << ' ';
        }
        else{
            ans += mp[a[i]];
            mp[a[i]]++;
            cout << ans << ' ';
        }
    }
    
}