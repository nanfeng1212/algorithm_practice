#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,h;
    cin >> l >> h;
    if (l%2) {
        cout << h << endl;
    }
    else  cout << 2*(h/2) << endl;
}