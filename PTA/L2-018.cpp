#include <bits/stdc++.h>
using namespace std;

map<int, double, greater<>> s;
map<int, double, greater<int>> y;
map<int, double, greater<int>> a;
map<int, double, greater<int>> b;
void fun() {
    if (a.empty()||a.empty()) return;
    int e1 = (*a.begin()).first;
    double c1 = (*a.begin()).second;
    int e2 = (*b.begin()).first;
    double c2 = (*b.begin()).second;
    if (e1<e2) {
        y = a;
        return;
    }
    s.insert({e1-e2, c1/c2});
    for (auto [e, c]: b) {
        int new_e = e1-e2+e;
        double new_c = (c1/c2)*c;
        a[new_e] -= new_c;
        if(a[new_e]==0) a.erase(a.find(new_e));
    }
    fun();
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        double y;
        cin >> x >> y;
        a.insert({x, y});
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        double y;
        cin >> x >> y;
        b.insert({x, y});
    }
    fun();
    for (auto i=s.begin(); i!=s.end();) {
        if (fabs(i->second)<0.05)
            i=s.erase(i);
        else i++;
    }
    if (s.size()==0) cout << "0 0 0.0\n";
    else {
        cout << s.size();
        for (auto i:s) printf(" %d %.1f", i.first, i.second);
        cout << endl;
    }
    for (auto i=y.begin(); i!=y.end();) {
        if (fabs(i->second)<0.05) i = y.erase(i);
        else i++;
    }
    if (y.size()==0) cout << "0 0 0.0\n";
    else {
        cout << y.size();
        for (auto i: y) printf(" %d %.1f", i.first, i.second);
        cout << endl;
    }
}
