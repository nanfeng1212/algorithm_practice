#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct ty {
    string id;
    int s;
}a[10010];
bool cmp(ty x, ty y) {
    if(x.s==y.s) return x.id<y.id;
    else return x.s>y.s;
}
int main(){
    int n, g, k;
    cin >> n >> g >> k;
    int sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i].id >> a[i].s;
        if (a[i].s>=60) {
            if (a[i].s<g) sum += 20;
            else sum += 50;
        }
    }
    cout << sum << endl;
    sort(a+1,a+1+n,cmp);
    int cur = 0;
    int cnt = 1;
    while (cur<=k) {
        if (cnt==1) {
            cur = 1;
            cout << cur << ' ' << a[cnt].id << ' ' << a[cnt].s << endl;
        }
        else {
            if(a[cnt].s==a[cnt-1].s){
                cout << cur << ' ' << a[cnt].id << ' ' << a[cnt].s << endl;
            }
            else {
                cur = cnt;
                if (cur<=k)
                    cout << cur << ' ' << a[cnt].id << ' ' << a[cnt].s << endl;
            }
        }
        cnt++;
    }

}