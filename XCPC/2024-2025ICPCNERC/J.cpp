#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cur=0;
    for(int i = 0; i < n; i++){
        char c;int k;
        cin >> c >> k;
        if(c=='P'){
            cur+=k;
        }
        if(c=='B'){
            if(cur>=k){
                cur -= k;
                cout << "NO" << endl;
            }
            else{
                cur = 0;
                cout << "YES" << endl;
            }
        }
    }
}