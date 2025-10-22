#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    double d,s;
    cin >> d >> s;
    double ans = (d-k*s/n)*n/(n-k);
    if (ans<0||ans>100)cout << "impossible";
    else printf("%.6f",ans);
}