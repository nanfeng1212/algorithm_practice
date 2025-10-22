#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[11];
const int mod = 998244353;
int qsm(int x,int y){
    int ans = 1;
    while(y){
        if(y&1)ans = (ans*x)%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return ans;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        memset(a,0,sizeof(a));
        for(int i=1;i<=9;i++)
            cin >> a[i];
        while(a[1]>=2){
            while(a[2]>=2&&a[1]){
                a[3]++;
                a[2]--;
                a[1]--;
            }
            if(a[1]>=2){
                a[2]++;
                a[1]-=2;
            }
        }
        int flag = 0;
        if(a[1])flag = 1;
        int ans = 1;
        for(int i=2;i<=10;i++){
            if(a[i]&&flag){
                a[i]--;
                flag = 0;
                a[i+1]++;
            }
            if(a[i])ans = ans*qsm(i,a[i])%mod;
        }
        cout << ans << endl;
    }
}