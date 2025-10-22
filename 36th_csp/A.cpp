#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,k;
    cin >> n >> k;
    while(k--) {
        int x,y;
        cin >> x >> y;
        string s;
        cin >> s;
        for (auto i:s){
            if (i=='f'&&y<n)y++;
            if (i=='b'&&y>1)y--;
            if (i=='l'&&x>1)x--;
            if (i=='r'&&x<n)x++;
        }
        cout << x << ' ' << y << '\n';
    }
}