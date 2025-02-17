#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010],sum[200010];
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i=1;i<=n;i++){
        ans += a[i]*(sum[n]-sum[i]);
    }
    cout << ans << endl;
    return 0;
 
}