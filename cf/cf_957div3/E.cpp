#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s="";
        vector<pair<int,int>>ans;
        ans.clear();
        int p=n;
        int cnt = 0;
        while(p){
            cnt++;
            char c = '0'+p%10;
            s= c+s;
            p/=10;
        }
        for(int a=1;a<=10000;a++){
            int minb = max(1,cnt*a-5);
            int maxb = a*cnt;
            for(int b=minb;b<maxb;b++){
                int x = n*a-b;
                int y = 0;
                for(int i=0;i<a*cnt-b;i++){
                    y = y*10 + s[i%cnt]-'0';
                }
                if(x==y)ans.push_back({a,b});
            }
        }
        cout << ans.size() << endl;
        for(auto i:ans){
            cout << i.first << " " << i.second << endl;
        }
    }
}