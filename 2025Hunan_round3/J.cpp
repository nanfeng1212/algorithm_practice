#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int k = 0;
        for(int i=1; i<=m; i++){
            int u,v;
            cin >> u >> v;
            if(v>u) k++;
        }
        if(k*2<m){
            for (int i=n; i>=1; i--)  
                cout<<i<<" ";
            cout<<"\n";
        }
        else{
            for(int i=1; i<=n; i++)
                cout<<i<<" ";
            cout<<"\n";
        }
    }
    return 0;
}