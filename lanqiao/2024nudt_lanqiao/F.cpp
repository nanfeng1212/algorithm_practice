#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 4){
            cout << -1 << endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(i%2 && i!=5){
                cout << i << ' ';
            }
        }
        cout << 5 << ' ' << 4 << ' ';
        for(int i=1;i<=n;i++){
            if(i%2==0 && i!=4){
                cout << i <<' ';
            }
        }
        cout << endl;
    }
}