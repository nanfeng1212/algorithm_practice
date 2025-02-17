#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    cout << x << endl;
    int s = x;
    while(s > 1){
        int k = 0;
        long long v = 1;
        while(1){
            k++;
            v *= s;
            if(v >= x)break;
        }
        if(v == x)
            cout << "=" << s << "^" << k <<endl;
        s--;
    }
    return 0;
}