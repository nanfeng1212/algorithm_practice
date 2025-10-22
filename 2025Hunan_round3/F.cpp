#include<bits/stdc++.h>
using namespace std;

int t[22];
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a,b;
        char c;
        cin >> a >> c >> b;
        t[i] = 60*(a-7)+b;
    }
    int flag = 0;
    for (int i=3; i<=n; i++) {
        if (t[i]-t[i-2]<=10)flag = 1;
    }
    if (flag) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=2; i<=n; i++) {
        if (t[i]-t[i-1]<=10)flag = 1;
    }
    if (flag)cout << 1 << endl;
    else cout << 2 << endl;


}