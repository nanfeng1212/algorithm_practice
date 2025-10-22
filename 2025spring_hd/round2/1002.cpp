#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e16+1029;
map<string, int> mp;
string t[10] = {"jia","yi","bing","ding","wu","ji","geng","xin","ren","gui"};
string d[12] = {"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};
int main() {
    int k = 1984;
    int i = 0, j = 0;
    while(k<=2043) {
        mp[t[i]+d[j]] = k;
        k++;
        i++;
        j++;
        if(i==10) i=0;
        if(j==12) j=0;
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << mp[s] << endl;
    }

}