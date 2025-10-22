#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<double,vector<double>,less<double>>q;
int main(){
    int n,m,k;
    cin >> n >> k >>m;
    while (n--){
        double ans = 0;
        vector<double>a(k);
        for (int i=0; i<k; i++)cin >> a[i];
        sort(a.begin(),a.end());
        for (int i=1; i<k-1; i++) ans+=a[i];
        ans /= k-2;
        q.push(ans);
    }
    vector<double>ans;
    while(m--) {
        double res = q.top();
        q.pop();
        ans.push_back(res);
    }
    sort(ans.begin(),ans.end());
    for (int i=0; i<ans.size(); i++){
        if (i==0) cout << fixed << setprecision(3) << ans[i];
        else cout << ' ' << fixed << setprecision(3) << ans[i];
    }
}