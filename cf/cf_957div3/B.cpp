#include<bits/stdc++.h>
using namespace std;

long long a[100010];
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        for(int i=1;i<=k;i++)cin >> a[i];
        sort(a+1,a+1+k);
        long long ans = 0;
        for(int i=1;i<k;i++){
            if(a[i]==1)ans+=a[i];
            else ans+=a[i]-1+a[i];
        }
        cout << ans << endl;
    }
}