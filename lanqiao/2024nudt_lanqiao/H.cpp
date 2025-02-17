#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int flag = 0;
        cin >> n;
        string s = "";
        int first = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            s+='0';
        }
        int old = 0, cur = 0;
        cout << '?' << ' ' << 1 << ' ' << 2 << endl;
        cout.flush();
        cin >> cur;
        if(cur){
            flag = 1;
            old = 1;
            first = 2;
            cnt = 1;
            s[0] = '0';
            s[1] = '1';
        }
        for(int i=3;i<=n;i++){
            cout << '?' << ' ' << 1 << ' ' << i << endl;
            cout.flush();
            cin >> cur;
            if(cur>old){
                s[i-1] = '1';
                if(!flag){
                    flag = 1;
                    first = i;
                    cnt = cur;
                }
            }
            else{
                s[i-1] = '0';
            }
            old = cur;
        }
        if(!flag){
            cout << '!' << ' ' << "IMPOSSIBLE" << endl;
            cout.flush();
            continue;
        }
       // cout << first << ' ' << cnt << endl;
        for(int i=first-2-cnt;i>=0;i--) s[i]='1';
        cout << '!' << ' ' << s << endl;
        cout.flush();
    }
}