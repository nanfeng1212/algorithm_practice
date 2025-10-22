#include<bits/stdc++.h>
using namespace std;

int n,m;
struct ty{
    long long x,cur;
};
struct node{
    long long i,t;
    bool operator < (const node &b) const {
        return t > b.t;
    }
};
ty a[100010];
long long x[100010],t[100010];
long long nxt[100010];
long long c[100010];
priority_queue<node> q;
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        long long ans = 0;
        for(int i=1; i<=n; i++)
        {    
            cin >> a[i].x;
            a[i].cur = a[i].x;
            ans += a[i].x;
            //q.push({i,(long long)1e18+1});
        }
        for(int i=1; i<=m; i++)
        {
            cin >> x[i] >> t[i];
            //q.push({t[i],x[i]});
        }
        for(int i=1; i<=n; i++)
            c[i] = 1e18;
        for(int i=m; i>=1; i--){
            nxt[i] = c[t[i]];
            c[t[i]] = i;
        }
        for(int i=1; i<=n; i++)
            q.push({i,c[i]});
        for(int i=1; i<=m; i++){
            long long p = x[i]-x[i-1];
            while(p && !q.empty()){
                node cur = q.top();
                q.pop();
                if(a[cur.i].cur>=p){
                    a[cur.i].cur -= p;
                    p = 0;
                    if(cur.i!=t[i])q.push(cur);
                }
                else{
                    p -= a[cur.i].cur;
                    a[cur.i].cur = 0;
                }
            }
            if(p)break;
            ans += a[t[i]].x - a[t[i]].cur;
            a[t[i]].cur = a[t[i]].x;
            q.push({t[i],nxt[i]});
        }
        while(q.size())q.pop();
        cout << ans << endl;
    }
}