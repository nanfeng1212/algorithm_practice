#include<bits/stdc++.h>
using namespace std;
#define ll long long
double cur;
set<int>v;
struct point{
    int idx;
    int ans;
    int vis;
    double rad;
    ll l;
    ll z;
    bool operator>(point b)const{
        double r1,r2;
        if(fabs(rad-cur)<=1e-8){
            return 1;
        }
        if(fabs(b.rad-cur)<=1e-8){
            return 0;
        }
        if(rad>=cur)r1 = rad-cur;
        else r1 = 2*M_PI+rad-cur;
        if(b.rad>=cur)r2 = b.rad-cur;
        else r2 = 2*M_PI+b.rad-cur;
        return r1>=r2;
    }
}a[200010];
int n, cnt = 0, cnt2 = 0;
ll L;
priority_queue<point,vector<point>,greater<point>>q;
int main()
{

	cin >> n >> L;
	for(int i=1; i<=n; i++){
        ll x,y;
        v.insert(i);
        cin >> y >> x >> a[i].z;
        a[i].idx = i;
        a[i].vis = 0;
        a[i].ans = -1;
        a[i].l = x*x+y*y;
        if(x>=0&&y==0){
            if(a[i].l<=L*L){
                cnt2++;
                if(!cnt)cnt=cnt2;
                a[i].ans = cnt;
                L += a[i].z;
                a[i].vis = 1;
                v.erase(i);
            }
            else
                a[i].rad = (double)atan2(y,x);
        }
        else if(x==0){
            if(y>=0)a[i].rad = M_PI*(double)1.0/2.0;
            else a[i].rad = M_PI*(double)3.0/2.0;
        }
        else if(y==0)
            a[i].rad = M_PI;
        else if(y>0)
            a[i].rad = (double)atan2(y,x);
        else
            a[i].rad = (double)atan2(y,x)+2*M_PI;
    }
    cur = 0.0;
    for(int i=1;i<=n;i++){
        if(a[i].l<=L*L&&a[i].vis==0){
            a[i].vis = 1;
            v.erase(i);
            q.push(a[i]);
        }
    }
    while(!q.empty()){
        point t = q.top();
        q.pop();
        if(fabs(cur-t.rad)>1e-16){
            a[t.idx].ans = ++cnt2;
            cur = t.rad;
            cnt =  cnt2;
        }
        else{
            a[t.idx].ans = cnt;
        }
        L += t.z;
        vector<int>vv;
        vv.clear();
        for(auto i:v){
            if(a[i].l<=L*L){
                a[i].vis = 1;
                vv.push_back(i);
                q.push(a[i]);
            }
        }
        for(auto i:vv)v.erase(i);
    }
    int ans[200010];
    for(int i=1;i<=n;i++){
        ans[a[i].idx] = a[i].ans;
    }
    for(int i=1; i<=n; i++)
        cout << ans[i] << " ";
    cout << '\n';
	return 0;
}