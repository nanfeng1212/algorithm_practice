#include<bits/stdc++.h>
using namespace std;
#define int long long 
int l[200010],r[200010];
struct ty{
    int x;
    int v;
}a[200010];
bool cmp(ty x, ty y){
    return x.v>=y.v;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,L;
        int ans=0;
        int pow = 1;
        priority_queue<int> q;
        cin >> n >> m >> L;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        a[m+1] = {L,0};
        for(int i=1;i<=n;i++){
            cin >> l[i] >> r[i];
        }
        for(int i=1;i<=m;i++){
            cin >> a[i].x >> a[i].v;
        }
        int flag = 1;
        int i=1;
        for(int j=1;j<=n;j++){
            while(a[i].x<=l[j]&&i<=m){
                q.push(a[i].v);
                i++;
            }
            while(pow<r[j]+1-(l[j]-1) && !q.empty()){
                pow += q.top();
                ans++;
                q.pop();
            }
            if(pow<r[j]+1-(l[j]-1)){
                flag = 0;
                break;
            }
        }
        if(!flag) cout << -1 <<endl;
        else cout << ans <<endl;
    }
}