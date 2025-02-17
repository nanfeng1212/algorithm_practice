#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll exgcd(ll &x, ll &y, ll a, ll b)
{
    if(!b){
        x = 1, y = 0;
        return a;
    }
    ll g = exgcd(x, y, b, a % b);
    ll t = x; x = y;
    y = t - a / b * y;
    return g;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int t = 1;
    while(b % 2 == 0) {
        b /= 2;
        t *= 2;
    }
    while(b % 5 == 0) {
        b /= 5;
        t *= 5;
    }
    ll tx, ty;
    exgcd(tx, ty, t, b);
    ll c = b * t - a, d = b * t;
    for(ll p2 = 1; p2 * b <= 1e9; p2 *= 2) {
        for(ll p5 = p2; p5 * b <= 1e9; p5 *= 5) {
            ll den = -a * p5;
            ll x = tx * den;
            x = (x % b + b) % b;
            if(x < c) {
                c = x;
                d = b * p5;
            }
        }
    }
    cout << c << ' ' << d << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}