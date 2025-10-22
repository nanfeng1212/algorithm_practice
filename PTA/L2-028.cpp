#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ty{
    string id;
    double s;
};
set<string>p[1010];
int main(){
	int n, m;
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int k;
        cin >> k;
        while (k--) {   
            string cur;
            cin >> cur;
            p[i].insert(cur);
        }
    }
    string a,b;
    cin >> a >> b;
    map<string, double>ma;
    map<string, double>mb;
    for (int j=1; j<=m; j++) {
        if (p[j].count(a)) {
            for (auto i:p[j]) {
                if (i==a)continue;
                if (a[0]==i[0]&&a[0]=='-')continue;
                if (a[0]=='-'||i[0]=='-') {
                    ma[i] += 1.0/double(p[j].size());
                }
            }
        }
        if (p[j].count(b)) {
            for (auto i:p[j]) {
                if (i==b)continue;
                if (b[0]==i[0]&&b[0]=='-')continue;
                if (b[0]=='-'||i[0]=='-'){
                    //cout << i << ' ' << p[j].size() << endl;
                    mb[i] += 1.0/double(p[j].size());
                }
            }
        }
    }
    set<int>ansa, ansb;
    double cur = 0.0;
    for (auto [x,y]:ma) {
        if (y>cur) {
            ansa.clear();
            cur = y;
            ansa.insert(abs(stoi(x)));
        }
        else if(y==cur) ansa.insert(abs(stoi(x)));
    }
    cur = 0.0;
    for (auto [x,y]:mb) {
        if (y>cur) {
            ansb.clear();
            cur = y;
            ansb.insert(abs(stoi(x)));
        }
        else if(y==cur) ansb.insert(abs(stoi(x)));
    }
    if (!ansa.size()&&!ansb.size()){
        cout << a << ' ' << b;
        return 0;
    }
    if (stoi(a)>0) {
        if (ansb.count(stoi(a))&&ansa.count(-1*stoi(b))) {
            cout << a << ' ' << b << endl;
            return 0;
        }
        for (auto i:ansa) 
            cout << a << " -"  << i << endl;
        for (auto i:ansb) {
            cout << b << ' ' << i << endl;
        }
    }
    else {
        if (ansa.count(stoi(b))&&ansb.count(-1*stoi(a))) {
            cout << a << ' ' << b << endl;
            return 0;
        }
        for (auto i:ansa) 
            cout << a << " "  << i << endl;
        for (auto i:ansb) {
            cout << b << " -"  << i << endl;
        }
    }
    return 0; 
}
