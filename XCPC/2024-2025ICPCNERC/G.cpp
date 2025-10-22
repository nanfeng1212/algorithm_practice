#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int one=0,zero=0;
        cout << 1 << ' ' << 1 << endl;
        cout.flush();
        cin >> one;
        zero = n-one;
        if(one==0){
            cout << 0 << ' ' << n << ' ' << 0 << endl;
            cout.flush();
            int res;
            cin >> res;
            continue;
        }
        if(zero==0){
            cout << 0 << ' ' << n << ' ' << 1 << endl;
            cout.flush();
            int res;
            cin >> res;
            continue;
        }
        if(one>zero){
            int onezero=0,oneone=0;
            cout << 1 << ' ' << "10" << endl;
            cout.flush();
            cin >> onezero;
            cout << 1 << ' ' << "11" << endl;
            cout.flush();
            cin >> oneone;
            int left = one - onezero;
            if(left>oneone){
                cout << 0 << ' ' << n <<  ' ' << 1 << endl;
                cout.flush();
                int res;
                cin >> res;
            }
            else{
                cout << 0 << ' ' << n << ' ' << 0 <<endl;        
                cout.flush();
                int res;
                cin >> res;
            }
        }
        else{
            int zeroone=0,zerozero=0;
            cout << 1 << ' ' << "01" << endl;
            cout.flush();
            cin >> zeroone;
            cout << 1 << ' ' << "00" << endl;
            cout.flush();
            cin >> zerozero;
            int left = zero - zeroone;
            if(left>zerozero){
                cout << 0 << ' ' << n <<  ' ' << 0 << endl;
                cout.flush();
                int res;
                cin >> res;
            }
            else{
                cout << 0 << ' ' << n << ' ' << 1 <<endl;        
                cout.flush();
                int res;
                cin >> res;
            }
        }
    }
}