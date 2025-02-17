#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            int cnt = 1;
            for(int i=1;i<=n;i+=2){
                cout << cnt << " " << cnt <<' ';
                cnt++;
            }
            cout << endl;
            continue;
        }
        if(n<27){cout << -1 << endl;continue;}
        int v[200010];
        for(int i=1;i<=n;i++){
            v[i] = 0;
        }
        v[1] = 1;
        v[10] = 1;
        v[11] = 2;
        v[26] = 1;
        v[27] = 2; 
        int cnt = 3;
        int c = 0;
        for(int i=1;i<=n;i++){
            if(!v[i]){
                c++;
                v[i] = cnt;
                if(c%2==0)cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            cout << v[i] << ' '; 
        }
        cout << endl;
    }
}