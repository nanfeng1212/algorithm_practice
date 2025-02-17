#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        int ans = a*b*c;
        for(int i=0;i<=5;i++){
            for(int j=0;j<=5-i;j++){
                for(int k=0;k<=5-i-j;k++){
                    ans = max(ans,(a+i)*(b+j)*(k+c));
                }
            }
        }
        cout << ans << '\n';
    }
}