#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.length() ==1){cout << -1<<endl;continue;}
        int flag = 0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                flag = 1;
                cout << s[i]<< s[i]<<endl;
                break;
            }
        }
        if(flag)
            continue;
        for(int i=0;i<s.length()-2;i++){
            if(s[i]!=s[i+1]&&s[i+1]!=s[i+2]&&s[i+2]!=s[i]){
                flag = 1;
                cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
                break;
            }
        }
        if(flag)continue;
        else cout << -1 << endl;    
    }
}