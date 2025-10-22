#include<bits/stdc++.h>

using namespace std;
int n;
string s;
string ss="01";
vector<int>v;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        if(n%2){
            cout<<"-1"<<endl;
            continue;
        }
        int cnt=0;
        v.clear();
        int i=0;
        while(i<n/2&&cnt<=300)
        {
            if(s[i]!=s[n-i-1])i++;
            else{
                if(s[i]=='0')
                {
                    s.insert(n-i,ss);
                    cnt++;
                    v.push_back(n-i);
                }
                else{
                    s.insert(i,ss);
                    cnt++;
                    v.push_back(i);
                }
                i=0;
                n=s.length();
            }
        }
        if(cnt<=300)
        {
            cout<<cnt<<endl;
            for(int i=0;i<v.size();i++)
                cout<<v[i]<<' ';
            cout<<endl;
        }
        else cout<<-1<<endl;

    }
    return 0;
}
