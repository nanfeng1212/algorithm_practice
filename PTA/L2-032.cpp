#include<bits/stdc++.h>
using namespace std;

int vis[1010];
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;
    while (k--) {
        int cnt = 0;
        stack<int>st;
        int cur = 1;
        memset(vis,0,sizeof vis);
        int flag = 1;
        for (int i=1; i<=n; i++) {
            int p;
            cin >> p;
            vis[p] = 1;
            if (cur==p) {
                cur++;
                while (!st.empty()&&st.top()==cur) {
                    st.pop();
                    cur++;
                    }
                continue;
            }
            else {
                st.push(p);
                if (st.size()>m)flag = 0;
            }
        }
        while (!st.empty()&&st.top()==cur) {
            st.pop();
            cur++;
        }
        if (!flag || cur<=n) cout << "NO\n";
        else cout << "YES\n";
    }

}
