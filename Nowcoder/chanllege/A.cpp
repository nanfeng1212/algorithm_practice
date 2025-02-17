#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l,m;
        cin >> l >> m;
        if(m==1){
            cout << 1 <<endl;
            continue;
        }
        int ans = 0;
        int k = 0;
        int sum = 0;
        while(sum<m && l-sum>(1<<k)){
            sum+=1<<k;
            k++;
        }
        cout << k << endl;
    }
}