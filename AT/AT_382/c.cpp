#include<bits/stdc++.h>
using namespace std;
int vis[200010];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        for(int j=a;j<=2e5;j++){
            if(!vis[j])
                vis[j] = i;
            else break;
        }
    }
    for(int i=1;i<=m;i++){
        int b;
        cin >> b;
        if(vis[b]){
            cout << vis[b] <<'\n';
        }
        else cout << -1 << '\n';
    }
    
    return 0;
    
}