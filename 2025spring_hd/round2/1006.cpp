#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t = 1;
    cin >> t;
    while (t--){
        ll r,b,m;
        cin >> r >> b >> m;
        if(r==0 && b==0){
            if(m)cout<<"Bob\n";
            else cout<<"Alice\n";
            continue;
        }
        if(b%2){
            r = (r+1)%4;
            bool f =  0;
            if(r==3){
                f = false;
            }
            else f = true;
            if(f){
                cout<<"Alice\n";
            }
            else cout<<"Bob\n";
        }
        else{
            r %= 4;
            bool f =  false;
            if(!r){
                f = false;
            }
            else f = true;
            if(f){
                cout<<"Alice\n";
            }
            else cout<<"Bob\n";
        }
    }
}