#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,int>mp;
int dat[1000010];
set<int>s;
int main(){
    int s;
    cin >> s;
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int cur, d, nex;
        cin >> cur >> d >> nex;
        mp[cur] = nex;
        dat[cur] = d; 
    }
    vector<int>ans;
    ans.push_back(s);
    while (mp[s]!=-1) {
        ans.push_back(mp[s]);
        s = mp[s];
    }
    int l = 0, r = ans.size()-1;
    int flag = 1;
    vector<int>res;
    while (l!=r) {
        if (flag) {
            flag = 0;
            res.push_back(ans[r]);
            r--;
        }
        else{
            flag = 1;
            res.push_back(ans[l]);
            l++;
        }
    }
    res.push_back(ans[l]);
    res.push_back(-1);
    n = res.size();
    for (int i=0; i<=n-3; i++) {
        string ss = to_string(res[i]);
        string ss1 = to_string(res[i+1]);
        while (ss.length()<5){
            ss = '0'+ss;
        }
        while (ss1.length()<5){
            ss1 = '0'+ss1;
        }
        cout << ss << ' ' << dat[res[i]] << ' ' << ss1 << endl;
    }
    string ss = to_string(res[n-2]);
    while (ss.length()<5){
        ss = '0'+ss;
    }
    cout << ss << ' ' << dat[res[n-2]] << ' ' << -1 << endl;
}