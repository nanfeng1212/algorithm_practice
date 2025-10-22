#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s, sum, now, ans;
ll p[1000010], c[1000010], cnt[1000010];
int main()
{
	cin >> n >> s;
    ll maxn = 0;
	for (int i=1; i<=n; i++){
		cin >> p[i] >> c[i];
        maxn = max(maxn,c[i]);
        now += p[i];
        sum += p[i] * c[i];
        cnt[c[i]] += p[i];
    }
	for (int i = 1; i <= maxn; i++) {
		if (now < s)  break;
		ans += s;
		sum -= now;
		now -= cnt[i];
	}
	cout << ans + sum;
	return 0;
}