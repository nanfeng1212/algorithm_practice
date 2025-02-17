#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r[1000010],d[1000010],s[1000010],t[1000010];
int n,m;
bool judge(int mid){
    int cha[1000010]={0};//差分数组
    int r1[1000010]={0};
    for(int i=1;i<=n;i++)     r1[i]=r[i];//拷贝数组r 
    for(int i=1;i<=mid;i++){
        cha[s[i]]-=d[i];
        cha[t[i]+1]+=d[i];
    }
    for(int i=1;i<=n;i++){
        cha[i]+=cha[i-1];
        r1[i]+=cha[i];
        if(r1[i]<0)        return false;//教室不够分 
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> r[i];
    }
    for(int i=1;i<=m;i++){
        cin >> d[i] >> s[i] >> t[i];
    }
    int l=0,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(judge(mid))    l=mid+1;
        else            r=mid-1;
    }
    if(l-1==m)    cout << "0\n";
    else{
        cout << "-1\n";
        cout << l << "\n";
    }
    return 0;
}