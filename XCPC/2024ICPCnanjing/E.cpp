#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s = s+s;
        int ans = 0;
        for(int i=0;i<=n-7;i++)
            if(s[i]=='n'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]=='j'&&s[i+4]=='i'&&s[i+5]=='n'&&s[i+6]=='g')
                ans++;
        for(int i=n-6;i<=n-1;i++)
            if(s[i]=='n'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]=='j'&&s[i+4]=='i'&&s[i+5]=='n'&&s[i+6]=='g'&&(7-(n-i))<=k)
                ans++;
        cout << ans << "\n";
    }
}