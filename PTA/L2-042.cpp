#include <bits/stdc++.h>
using namespace std;

set<pair<string, string>> record;
string st, ed;
int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> st >> ed >> ed;
        record.insert({st, ed});
    }
    record.insert({"23:59:59", ""});
    string begin = "00:00:00";
    for(auto it:record){
        if(begin<it.first)
            cout << begin << " - " << it.first << endl;
            begin = it.second;
    }
    return 0;
}