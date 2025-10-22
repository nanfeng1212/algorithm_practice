#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int>a;
    stack<char>b;
    for (int i=1; i<=n; i++) {
        int p;
        cin >> p;
        a.push(p);
    }
    for (int i=1; i<n; i++) {
        char c;
        cin >> c;
        b.push(c);
    }
    while (!b.empty()) {
        char c = b.top();
        b.pop();
        int p = a.top();
        a.pop();
        int q = a.top();
        a.pop();
        if (p==0&&c=='/') {
            cout << "ERROR: " << q << '/' << p;
            return 0;
        }
        if (c=='+') a.push(p+q);
        if (c=='-') a.push(q-p);
        if (c=='*') a.push(q*p);
        if (c=='/') a.push(q/p);
    }
    cout << a.top();

}
