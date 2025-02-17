#include <bits/stdc++.h>
using namespace std;
int a[2][2];
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a[0][0] >> a[0][1];
        cin >> a[1][0] >> a[1][1];
        int cnt = 0;
        int ans = min(a[0][0],a[0][1]);
        a[0][0] -= ans;
        a[0][1] -= ans;
        cnt += ans;
        ans = min(a[1][0],a[0][0]);
        cnt += ans;
        a[0][0] -= ans;
        a[1][0] -= ans;
        ans = min(a[0][1],a[1][1]);
        a[0][1] -= ans;
        a[1][1] -= ans;
        cnt += ans;
        ans = min(a[1][1],a[1][0]);
        cnt += ans;
        a[1][1] -= ans;
        a[1][0] -= ans;
        if(cnt % 2)cout << "kou" << endl;
        else cout << "yukari" << endl;
    }
}