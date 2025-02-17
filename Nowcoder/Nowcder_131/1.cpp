#include<bits/stdc++.h>
using namespace std;
struct ty{
    int i;
    long long h;
}a[200010];
bool cmp(ty x,ty y){
    if(x.h==y.h)return x.i < y.i;
    else 
        return x.h < y.h;
}
int main(){
    int n;
    cin >> n;
    int m = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i].h;
        a[i].i = i;
    }
    sort(a+1,a+1+n,cmp);
    long long ans = 0;
    int pos = 0;
    for(int i=1;i<=n;i++){
        if(a[i].h*(n-i+1)*(n-i+1)>=ans){
            ans = a[i].h*(n-i+1)*(n-i+1);
            m = n-i+1;
            pos = i;
        }
    }
    cout << m << endl;
    vector<int>b;
    b.clear();
    for(int i=pos; i<=n; i++){
        b.push_back(a[i].i);
    }
    sort(b.begin(),b.end());
    for(auto i:b){
        cout << i << " ";
    }
}