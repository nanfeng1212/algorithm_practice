#include <bits/stdc++.h>
using namespace std;

char a[510][510];
int v[510][510];
int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m;
        memset(v, 0, sizeof v);
        memset(a, 0, sizeof a);
        cin >> n >> m;
        int f = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> a[i][j];
                if(a[i][j]=='.'){
                    if(i==1&&j==m)continue;
                    f = 1;
                }
            }
        }
        if(a[1][m] != '.'||f){
            cout << "No\n";
            continue;
        }
        int flag = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (a[i][j]=='C'){
                    v[i][j]++;
                    if(a[i][j-1]=='R'&&a[i+1][j]=='U'){
                        v[i][j-1]++;
                        v[i+1][j]++;
                    }
                    else if(a[i][j+1]=='L'&&a[i+1][j]=='U'){
                        v[i][j+1]++;
                        v[i+1][j]++;
                    }
                    else if(a[i][j+1]=='L'&&a[i-1][j]=='D'){
                        v[i][j + 1]++;
                        v[i - 1][j]++;
                    }
                    else if(a[i][j-1]=='R'&&a[i-1][j]=='D'){
                        v[i][j-1]++;
                        v[i-1][j]++;
                    }
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1;j<=m; j++){
                if(a[i][j]=='.'&&v[i][j]!=0){
                    flag = 0;
                }
                else if(v[i][j]!=1&&a[i][j]!='.'){
                    flag = 0;
                }
            }
        }
        if(!flag){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
    }
    return 0;
}