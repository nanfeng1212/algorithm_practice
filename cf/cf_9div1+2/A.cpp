#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << 2 << ' ';
        for(int i=2;i<=n;i++){
            cout << 2*i-1 << " ";
        }
        cout << endl;
    }
    
}