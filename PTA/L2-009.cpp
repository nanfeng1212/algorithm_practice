#include<bits/stdc++.h>
using namespace std;

int n;
struct ty{
    int cnt;
    int idx;
    double sum;
}a[10010];
bool cmp(ty a,ty b) {
    if (a.sum!=b.sum)return a.sum>b.sum;
    else{
        if (a.cnt!=b.cnt)return a.cnt>b.cnt;
        else return a.idx<b.idx;
    }
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int k;
        a[i].idx = i;
        cin >> k;
        while (k--) {
            int id;
            double p;
            cin >> id >> p;
            a[id].cnt++;
            a[id].sum += p;
            a[i].sum -= p;
        }
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1; i<=n; i++) {
        cout << a[i].idx << ' ' << fixed << setprecision(2)<< a[i].sum/100 << '\n';
    }
}