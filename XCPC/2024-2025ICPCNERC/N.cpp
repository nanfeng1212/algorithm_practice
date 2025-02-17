#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int x = s[0]-'0',y=s[2]-'0';
        if(s[1]=='='){
            if(x!=y)s[0]=s[2];
        }
        else if(s[1]=='>'){
            if(x<y){
                s[1]='<';
            }
            else if(x==y)s[1]='=';
        }
        else{
            if(x>y){
                s[1]='>';
            }
            else if(x==y)s[1]='=';
        }
        cout << s << endl;
    }
}