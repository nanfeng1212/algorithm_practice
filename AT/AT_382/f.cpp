#include<bits/stdc++.h>
using namespace std;

set<pair<int,int>>v[200010];

int main(){
    int h,w;
    int n;
    cin >> h >> w >> n;
    vector<int>r(n),c(n),l(n);
    for(int i=1;i<=n;i++){
        cin >> r[i] >> c[i] >> l[i];
        v[r[i]].insert({c[i],c[i]+l[i]-1});
    }
    for(int i=1;i<=n;i++){
        if(r[i]==h)continue;
        if(v[r[i]+1].size()==0){
            v[r[i]].erase({c[i],c[i]+l[i]-1});
            r[i]++;
            v[r[i]].insert({c[i],c[i]+l[i]-1});
        }
        else{
            int flag = 1;
            for(auto j:v[r[i]]){
                if((c[i]>=j.first&&c[i]<=j.second)||(c[i]+l[i]-1>=j.first&&c[i]+l[i]-1<=j.second)){
                    flag = 0;
                    break;
                }
            }
            if(!flag)continue;
            v[r[i]].erase({c[i],c[i]+l[i]-1});
            r[i]++;
            v[r[i]].insert({c[i],c[i]+l[i]-1});
        }         
    }
    for(int i=1;i<=n;i++)cout<<r[i]<<endl;  


    return 0;
    
}