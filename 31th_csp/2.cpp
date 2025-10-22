#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<double,double>> v(n+1);
    v[0] = {1,0};
    for(int i=1; i<=n; i++) {
        int op;
        cin >> op;
        if (op==1) {
            double k;
            cin >> k;
            v[i].first = v[i-1].first*k;
            v[i].second = v[i-1].second;
        }
        else {
            double k;
            cin >> k;
            v[i].first = v[i-1].first;
            v[i].second = v[i-1].second+k;
        }
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        double x,y;
        cin >> x >> y;
        x = x*(v[r].first/v[l-1].first);
        y = y*(v[r].first/v[l-1].first);
        double xx = x*cos(v[r].second-v[l-1].second)-y*sin(v[r].second-v[l-1].second);
        double yy = x*sin(v[r].second-v[l-1].second)+y*cos(v[r].second-v[l-1].second);
        cout <<fixed<< setprecision(2) << xx << " " << yy << endl;
    }

}