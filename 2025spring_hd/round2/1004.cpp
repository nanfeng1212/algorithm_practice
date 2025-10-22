#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll kind = 0;
int vis[26];
int fun(string s) {
    vector<int> dp(s.size(), 1); 
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        kind = 0;
        memset(vis,0,sizeof(vis));
        string s;
        int k = 0;
        string kk;
        cin >> s >> kk;
        if(kk.length()>=3)k=26;
        else k = stoi(kk);
        string ss = "";
        while(k--)ss+=s;
        cout << fun(ss)<< endl;
    }
    return 0;
}
