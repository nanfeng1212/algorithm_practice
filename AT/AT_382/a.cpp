#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    string s;
    cin >> n >> d;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='@')cnt++;
    }
    if(d>=cnt){
        cout << n << endl;
    }
    else{
        cout << n-(cnt-d) << endl;
    }
}