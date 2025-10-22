#include<bits/stdc++.h>
using namespace std;

vector<int>c[1010];
vector<pair<int,int>>ans;
int b[1010];
int a[1010];
int cnt;
void f(int l,int lc,int r){
    if(l>r)return;
    int mid = (l + r)/2;
    if(lc<a[mid]){
        for(int i=mid;i<=r;i++){
            for(int j=0;j<c[a[i]].size();j++){
                ans.push_back({2,c[a[i]][j]});
            }
        }
    }
    int rc=lc+1;
    while(rc<a[mid]){
        ans.push_back({1,rc});
        rc++;
    }
    //cout << mid << endl;
    f(mid+1,rc,r);
    f(l,lc,mid-1);
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> b[i];
        c[b[i]].push_back(i);
    }
    int flag = 1;
    for(int i=0;i<=n;i++){
        if(c[i].size())a[++cnt] = i;
    }
    int l = 1, r = cnt;
    int lc=0;
    f(l,lc,r);
    cout << ans.size()  << endl;
    for(auto [x,y]:ans){
        cout << x << ' '<<y << endl;
    }
}