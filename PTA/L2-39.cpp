#include <bits/stdc++.h>
using namespace std;

vector<int> temp;
map<vector<int>, int> A;
multimap<int, vector<int>, greater<int> > B;
int main() {
    int n, m;
    cin >> n >> m;
    temp.resize(m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) 
            cin >> temp[j];
        A[temp]++;
    }
    for (auto it : A) 
        B.insert({it.second, it.first});
    cout << A.size() << endl;
    for (auto it : B) {
        cout << it.first;
        for (auto it2 : it.second) cout << ' ' << it2;
        cout << '\n';
    }
    return 0;
}