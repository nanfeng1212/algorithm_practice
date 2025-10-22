#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll>v(n);
    for (int i=0; i<n; i++)cin >> v[i];
    sort(v.begin(),v.end());
    if (n%2) {
        ll ans = 0;
        for (int i=0; i<n/2; i++)ans-=v[i];
        for (int i=n/2; i<n; i++) ans+=v[i];
        cout << "Outgoing #: " << n/2+1 << '\n';
        cout << "Introverted #: " << n/2 << '\n'; 
        cout << "Diff = " << ans;
    }
    else {
        ll ans = 0;
        for (int i=0; i<n/2; i++) {
            ans += v[n-1-i]-v[i];
        }
        cout << "Outgoing #: " << n/2 << '\n';
        cout << "Introverted #: " << n/2 << '\n'; 
        cout << "Diff = " << ans;
    }
}