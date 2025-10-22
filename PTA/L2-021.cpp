#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int>s[110];
struct ty{
    int k;
    int cnt;
    string id;
}a[110];
bool cmp(ty x, ty y) {
    if (x.cnt==y.cnt) return x.k/double(x.cnt)<y.k/double(y.cnt);
    else return x.cnt>y.cnt;
}
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].id >> a[i].k;
        set<int>s;
        for (int j=1; j<=a[i].k; j++){
            int l;
            cin >> l;
            s.insert(l);
        }
        a[i].cnt = s.size();
        s.clear();
    }
    sort(a+1,a+1+n,cmp);
    /*for (int i=1; i<=n; i++) {
       cout << a[i].cnt << ' ' << a[i].cnt/a[i].k << ' ' << a[i].id <<endl;
    }*/
    if (n<3) {
        for(int i=1; i<=n; i++) cout << a[i].id << ' ';
        for (int i=n+1; i<3; i++) cout << "- ";
        cout << '-'; 
    }
    else {
        for (int i=1; i<3; i++) cout << a[i].id << ' ';
        cout << a[3].id;
    }
}