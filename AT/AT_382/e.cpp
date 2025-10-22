#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>v;
int main(){
    int n,x;
    cin >> n >> x;
    vector<double> p(n+1);
    for(int i=1;i<=n;i++)cin>>p[i];
    double c = 0;
    for(int i=1;i<=n;i++){
        c += p[i]/100;
    }
     
    printf("%.6f\n",ans);
    return 0;
    
}