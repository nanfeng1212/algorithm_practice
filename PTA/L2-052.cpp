#include<bits/stdc++.h>
using namespace std;

int l, n;
int ans;
int row[10], col[10];
void dfs(int x, int y){
    if (x==n && y>n) {
        for(int i=1; i<=n; i++) 
            if(row[i]!=l)
                return;
        for(int i=1; i<=n; i++) 
            if(col[i]!=k) 
                return;
        ans++;
        return;
    }
    if(y>n) x++, y = 1;
    for(int i=0; row[x]+i<=l && col[y]+i<=l; i++){
        if(x==n && col[y]+i!=l) continue;
        if(y==n && row[x]+i!=l) continue;
        row[x] += i;
        col[y] += i;
        dfs(x, y+1);
        row[x] -= i;
        col[y] -= i;
    }
}


int main(){
    cin >> l >> n;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
