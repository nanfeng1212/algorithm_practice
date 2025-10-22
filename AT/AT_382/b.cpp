#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    string s;
    cin >> n >> d;
    cin >> s;
    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        if(d == 0){
            break;
        }
        if(s[i] == '@'){
            s[i] = '.';
            d--;
        }
    }
    cout << s << endl;
    return 0;
    
}