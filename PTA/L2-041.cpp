#include <bits/stdc++.h>
using namespace std;

int n, m, k;
stack<int> st;
queue<int> q;
signed main(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        int p; 
        cin >> p; 
        q.push(p);
    }
    while(q.size()||st.size()) {
        int cnt = 0, last = 1010;
        bool flag = false;
        while(cnt<k){
            if(st.size()&&st.top()<=last){
                if(flag) cout << " ";
                cout << st.top();
                last = st.top(); 
                st.pop();
                cnt++; 
                flag = true;
            }
            else if(q.size()){
                int t = q.front();
                if(t<=last){
                    if(flag) cout << " ";
                    cout << t;
                    flag = true;
                    q.pop();
                    last = t; 
                    cnt++;
                }
                else if(st.size()<m){
                    st.push(t); 
                    q.pop();
                }
                else break;
            }
            else break;
        }
        cout << endl;
    }
}