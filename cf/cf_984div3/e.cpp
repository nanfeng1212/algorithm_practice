
/*
3 4 1
1 3 5 9
4 6 5 3
2 1 2 7
2
1 > 4
2 < 7
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector<vector<long long>>a(k,vector<long long>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin >> a[j][i];
    for(int i=0;i<k;i++){
        for(int j=1;j<n;j++){
            a[i][j]|=a[i][j-1];
            //cout << a[i][j] << ' ';    
        }
        //cout << endl;
    }
    while(q--){
        int m;
        cin >> m;
        int ans1 = n, ans2=1;
        while(m--){
            int r;
            char op;
            long long c;
            cin >> r >> op >> c;
            r--;
            if(op=='<'){
                int pos = lower_bound(a[r].begin(), a[r].end(),c)-a[r].begin();
                ans1 = min(ans1,pos);

            }
            else{
                int pos = upper_bound(a[r].begin(),a[r].end(),c)-a[r].begin();
                pos++;
                ans2 = max(ans2,pos);
            }
        }
        if(ans2>ans1)cout << -1 << endl;
        else cout << ans2 << endl;
    }
}