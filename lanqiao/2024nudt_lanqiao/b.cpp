#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[200010];
        for(int i=1;i<=n;i++){
            cin >> p[i];
        }
        int ans= 1;
        for(int i=1;i<n;i++){
            if(p[i]==i)continue;
            else if(p[i]==i+1&&p[i+1]==i){
                swap(p[i],p[i+1]);
            }
            else{
                ans = 0;
                break;
            }
        }
        if(ans)cout << "YES\n";
        else cout << "NO\n";
    }
}