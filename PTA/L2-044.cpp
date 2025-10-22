#include<iostream>
#include<vector>
using namespace std;
int g[510][510],sex[510],d[510];
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) 
                g[i][j]=0;
            else 
                g[i][j]=1e9;
        }
    }
    for(int i=1; i<=n; i++) {
        char op;
        int k;
        cin >> op >> k;
        if(op=='F') sex[i]=1; 
        else sex[i]=2;
        for(int j=1; j<=k; j++){
            int a,b;
            cin >> a >> op >> b;
            g[i][a]=b;
        } 
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(sex[i]!=sex[j])
                d[i] = max(d[i],g[j][i]);
    int d1 = 1e9;
    int d2 = 1e9;
    for(int i=1; i<=n; i++){
        if(sex[i]==2) 
            d1=min(d1,d[i]); 
        else
            d2=min(d2,d[i]); 
    }
    vector<int> a,b;
    for(int i=1; i<=n; i++){
        if(d[i]==d2&&sex[i]==1) 
            a.push_back(i);
        if(d[i]==d1&&sex[i]==2)
            b.push_back(i);
    }
    cout << a[0];
    for(int i=1; i<a.size(); i++) 
        cout << ' ' << a[i];
    cout << endl;
    cout << b[0]; 
    for(int i=1; i<b.size(); i++)
        cout << ' ' << b[i];
    return 0;
}
