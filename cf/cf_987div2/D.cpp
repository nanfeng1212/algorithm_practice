#include<bits/stdc++.h>
using namespace std;

int a[500010];
int ans[500010];
int pre[5000010];
int suf[500010];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pre[0] = 0;
        suf[n+1] = n+1;
        for(int i = 1; i<=n; i++){
            cin >> a[i];
            pre[i] = max(a[i],pre[i-1]);
        }
        for(int i=n;i>=1;i--){
            suf[i] = min(a[i],suf[i+1]);
        }
        ans[n] = pre[n];
        for(int i=n-1;i>=1;i--){
            ans[i] = pre[i];
            if(pre[i]>suf[i+1]){
                ans[i] = max(ans[i],ans[i+1]);
            }
        }
        for(int i=1;i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}