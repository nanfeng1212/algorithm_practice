#include <bits/stdc++.h>
using namespace std;
int main(){
    int K, L, lambda;
    cin >> K >> L >> lambda;
    vector<int> e(L+1,0);
    for (int i = 0; i < K; i++) {
        int op;
        cin >> op;
        if (op == 0){
            int pos, cur_e;
            cin >> pos >> cur_e;
            e[pos] += cur_e;
        } else if (op == 1) {
            int l, r;
            cin >> l >> r;
            
        }
    }
    return 0;
}
