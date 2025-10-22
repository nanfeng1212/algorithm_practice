#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> g[100010];
ll cnt[100010], a[100010], cnt1[100010], cnt2[100010], cnt3[100010];

int main() {
    for (int i=1; i<=100010; i++) {
        for (int j=i; j<=100010; j+=i) {
            g[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i=1; i<=n; i++) {
        for (int x : g[a[i]]) {
            cnt3[x]++;
            cnt1[i]+=cnt[x];
        }
        cnt1[i]--;
    }
    for (int i=1; i<=n; i++)
        cnt2[i]=cnt3[a[i]]-1;

    ll ans=0;
    for (int i=1; i<=n; i++) {
        ans += cnt1[i];
    }
    ans=ans*(ans-1);
    for (int i=1; i<=n; i++) {
        ans -= cnt2[i]*(cnt2[i]-1);
        ans -= cnt2[i]*cnt1[i];
        ans -= cnt2[i]*cnt1[i];
        ans -= cnt1[i]*(cnt1[i]-1);
    }   
    ll t=0;
    for (int i=1; i<=100010; i++) {
        ans += cnt[i]*(cnt[i]-1);
    }
    cout << ans << '\n';
    return 0;
}