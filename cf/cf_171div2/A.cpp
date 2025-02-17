#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,k;
        cin >> x >> y >> k;
        int x1=0,x2 = min(x,y),y1=0,y2 = min(y,x);
        int x3=min(x,y),x4=0,y3=0,y4=min(x,y);
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }
}