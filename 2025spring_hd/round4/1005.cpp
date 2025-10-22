#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int P, n, k;
        cin >> P >> n >> k;
        vector<int> d, r;
        for (int i=0; i<n; i++) {
            int t, p;
            cin >> t >> p;
            if (t == 0) {
                d.push_back(p);
            } else {
                r.push_back(p);
            }
        }
        sort(d.begin(), d.end());
        sort(r.begin(), r.end(), greater<int>());
        vector<double> pre_d(1, 1.0);
        for (int x : d) {
            pre_d.push_back(pre_d.back()*(x/10.0));
        }
        
        vector<long long> pre_r(1, 0);
        for (int y : r) {
            pre_r.push_back(pre_r.back() + y);
        }
        int m_d = d.size();
        int m_r = r.size();
        double min_p = 1e18;
        int a_min = max(0, k-m_r);
        int a_max = min(k, m_d);
        for (int a=a_min; a<=a_max; a++) {
            int b = k-a;
            if (b<0 || b>m_r) continue;
            double price = P*pre_d[a]-pre_r[b];
            price = max(price, 0.0);
            if (price < min_p) {
                min_p = price;
            }
        }
        cout << fixed << setprecision(2) << min_p << '\n';
    }
    return 0;
}