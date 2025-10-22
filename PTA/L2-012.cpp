#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
map<int,int>mp;
int a[1010];
void fun(int x) {
    while (a[x/2]>a[x]){
        mp[a[x/2]] = x;
        mp[a[x]] = x/2;
        swap(a[x],a[x/2]);
        x/=2;
    }
}
int main() {
    cin >> n >> m;
    a[0] = -11111;
    cin >> a[1];
    mp[a[1]] = 1;
    for (int i=2; i<=n; i++) {
        cin >> a[i];
        mp[a[i]]=i;
        fun(i);
    }
    getchar();
    while(m--) {
        string s;
        getline(cin,s);
        stringstream ss(s);
        vector<string>v;
        while(ss >> s){
            v.push_back(s);
        }
        if (v.size()==4) {
            int a = stoi(v[0]);
            if (mp[a]==1)cout << "T\n";
            else cout << "F\n";
        }
        else if (v.size()==5) {
            int a = stoi(v[0]);
            int b = stoi(v[2]);
            if (mp[a]/2==mp[b]/2) cout << "T\n";
            else cout << "F\n";
        }
        else{
            int a = stoi(v[0]);
            int b = stoi(v[5]);
            if (v[2]=="a") {
                if (mp[a]/2==mp[b])cout << "T\n";
                else cout << "F\n";
            }
            else {
                if (mp[a]==mp[b]/2)cout << "T\n";
                else cout << "F\n";
            }            
        }
    }


}