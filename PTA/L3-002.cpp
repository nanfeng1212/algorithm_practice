#include<bits/stdc++.h>
using namespace std;

vector<int> v;
stack<int> st;
int n;
int main(){
    cin >> n;
    v.clear();
    while (n--) {
        string s;
        cin >> s;
        if (s=="Pop") {
            if(v.size()==0) {
                cout << "Invalid" << endl;
                continue;
            }
            auto i = lower_bound(v.begin(),v.end(), st.top());
            cout << *i << endl;
            v.erase(i);
            st.pop();
        }
        else if(s=="Push") {
            int k;
            cin >> k;
            auto i = lower_bound(v.begin(),v.end(), k);
            v.insert(i, k);
            st.push(k);
        }
        else {
            if(v.size()==0){
                cout<<"Invalid"<<endl;
                continue;
            }
            cout << v[(v.size()-1)/2]<<endl;
        }
    }
}

