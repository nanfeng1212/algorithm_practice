#include<bits/stdc++.h>
using namespace std;
 
string mp[100010];
int flag=0;
int n, m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 
void dfs(int x,int y){
    if (x<0 || x>=n || y<0 || y>=m || mp[x][y]=='0') 
        return;
    if (mp[x][y]>'1') 
        flag=1;
    mp[x][y]='0';
    for(int i=0; i<4; i++)
        dfs(x+dx[i],y+dy[i]);
}
int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin>>mp[i];
    int ans=0;
    int cnt=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mp[i][j]>'0') {
                ans++;
                flag=0;
                dfs(i,j);
                if(flag) 
                    cnt++;
            }
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}