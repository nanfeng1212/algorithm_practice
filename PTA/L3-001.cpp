#include<bits/stdc++.h>
using namespace std;

int n,m; 
int a[10010];
int t,num, cnt;
int ans[100010];
void dfs(int now,int idx) {
    if(now==m) {
        for(int i=0; i<cnt; i++) {
            if(i) cout<<" ";
            cout<<ans[i];
        }
        exit(0);
    }
    if(now>m||idx>=num)	return;
    for(int i=idx+1; i<num; i++) {
        if(now+a[i]>m){
            return ; 
        }
        ans[cnt++]=a[i];
        dfs(now+a[i],i);
        cnt--;
    }
}
int main() {
    cin >> n >> m;
    int sum=0;
    while(n--) {
        cin >> t;
        sum+=t;
        a[num++]=t;
    }
    if(sum<m){
        cout<<"No Solution";
    return 0;
    }
    sort(a,a+num);
    dfs(0,-1);
    cout<<"No Solution";
    return 0;
}

