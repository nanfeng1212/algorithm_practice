#include<bits/stdc++.h>
using namespace std;
struct ty{ 
    string name;
    string id;
    string time;
    int state;
    int idx;
}a;
map<string,int>mp;
vector<ty>v;
map<string,string>ys;
vector<string>pq;
bool cmp(ty c, ty d){
    if(c.time==d.time) return c.idx<d.idx;
    return c.time<d.time;
}
int check(string s)
{
    for(int i=0; i<18; i++)
        if (!isdigit(s[i]))
            return 0;
    return 1;
}
int main()
{
   int d, p;
   cin >> d >> p;
    for(int t=1; t<=d; t++){
        int sum, cnt;
        cin >> sum >> cnt;
        for(int j=1; j<=sum; j++){
            cin >> a.name >> a.id >> a.state >>a.time; 
            a.idx = j;
            if(a.id.length()==18&&check(a.id)){
                if(a.state&&find(pq.begin(),pq.end(),a.id)==pq.end()){
                    ys[a.id]=a.name;
                    pq.push_back(a.id);
              }
              v.push_back(a);
          }
        }
        sort(v.begin(),v.end(),cmp);
        for(auto j:v){
            if(cnt==0) break;
            if(mp.find(j.id)==mp.end()||mp[j.id]<=t){
                cout << j.name << " " << j.id <<endl;
                mp[j.id]=t+p+1;        
                cnt--;
            }
        }
        v.clear();
    }
    for(auto j:pq)
        cout << ys[j] << " " << j <<endl;
}