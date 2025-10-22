#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int h[55];
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> h[i];
        }
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        int k = 0;
        int cnt = 1;
        int cur = h[1];
        for(int i=2;i<=n;i++){
            if(h[i]==cur)cnt++;
            else{
                k = max(cnt,k);
                cur = h[i];
                cnt = 1;
            }
        }
        k = max(cnt,k);
        cout << n-k << endl;
    }
}