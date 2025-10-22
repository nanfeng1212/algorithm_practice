#include<bits/stdc++.h>
using namespace std;
long long f(long long n){
    if(n%4==0)return n;
    if(n%4==1)return 1;
    if(n%4==2)return n+1;
    if(n%4==3)return 0;
}
long long fu(long long n,int i,long long k){
    if(i==0){
        if(k==0)return f(n);
        else return 0;
    }
    if(n<k)return 0;
    long long p = 1ll << i;
    long long m = (n-k)/p;
    long long cnt = m+1;
    long long res = f(m)*p;
    if(cnt%2)res^=k;
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long l,r,k;
        int i;
        cin >> l >> r >> i >> k;
        long long sum = f(r)^f(l-1);
        long long tmp = fu(r,i,k)^fu(l-1,i,k);
        cout << (long long)(sum^tmp) << endl;
    }
}