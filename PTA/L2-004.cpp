#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1010];
int flag=1;
int res[1010];
void dfs(int l, int r){
    if (l>r) return;
    int ll = l+1, rr = r;
    if (flag) {
        while(ll<=r&&a[l]>a[ll])ll++;
        while(rr>l&&a[l]<=a[rr])rr--;
    }
    else {
        while(ll<=r&&a[l]<=a[ll])ll++;
        while(rr>l&&a[l]>a[rr])rr--;
    }
    if (rr!=ll-1) return;
    dfs(l+1,rr);
    dfs(ll,r);
    res[++res[0]]=a[l];
}
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    dfs(1,n);
    if(res[0]!=n) {
        res[0] = 0;
        flag = 0;
        dfs(1,n);
    }
    if(res[0]==n){
        cout << "YES\n";
        for (int i=1; i<n; i++)
            cout << res[i] << ' ';
        cout << res[n];
    }
    else cout << "NO";
}