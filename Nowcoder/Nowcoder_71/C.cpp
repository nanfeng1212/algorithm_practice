#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;  
    cin>>s;
    map<char,int>mp;
    for(auto i:s){
        mp[i]++;
    }
    cout<<mp.size();
}