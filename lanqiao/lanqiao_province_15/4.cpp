#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long b[100010];
long long sum[100010];
long long sum2[100010];
long long n,k,T;
bool check(int x){
    for(int i=1; i<=x; i++)
        b[i]=a[i];
    sort(b+1,b+x+1);
    for(int i=1; i<=x; i++){
        sum[i] = sum[i-1]+b[i];
        sum2[i] = sum2[i-1]+b[i]*b[i];
    }
    double ans=1e30;
    for(int i=k; i<=x; i++){
        ans = min(ans,((sum2[i]-sum2[i-k])+((1.0*sum[i]-sum[i-k])/k)*((1.0*sum[i]-sum[i-k])/k)*k-2*(1.0*sum[i]-sum[i-k])*(1.0*sum[i]-sum[i-k])/k)/k);
    }
    return ans<T;
}
int main(){
    cin >> n >> k >> T;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int l = k, r = n;
    int ans = -1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
