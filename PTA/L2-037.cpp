#include<bits/stdc++.h>
using namespace std;

queue<char>q[101];
stack<char>st;
int main() {
    int n, m, sm;
    cin >> n >> m >> sm;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (auto j : s) q[i].push(j);
    }
    int p;
    cin >> p;
    while (p!=-1) {
        if (p==0) {
            if (st.empty());
            else {
                cout << st.top();
                st.pop();
            }
        }
        else {
            if (q[p].empty());
            else if (st.size()==sm) {
                cout << st.top();
                st.pop();
                st.push(q[p].front());
                q[p].pop();
            }
            else {
                st.push(q[p].front());
                q[p].pop();
            }

        }
        cin >> p;
    }


}