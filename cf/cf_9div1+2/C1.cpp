#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x;
        int ans = 0;
        long long m;
        cin >> x >> m;
        long long cnt;
        for(cnt = 20;cnt>=0;cnt--){
            if((x>>cnt)&1)break;
        }
        long long k = min((long long)((1<<(cnt+1))-1),m);
        for(long long i=1;i<=k;i++){
            if(i==x)continue;
            long long d = x^i;
            if(x%d==0)ans++;
            else if(i%d==0)ans++;
        }
        cout << ans << endl;
    }
}