#include<bits/stdc++.h>
#include<map>

using namespace std;
int n,m;
map<char,int>mp;
string s;
string t;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        mp.clear();
        cin>>n>>m;
        int flag1=1,flag2=1;
        int cnt=0;
        cin>>s;
        cin>>t;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                flag1=0;
                if(mp.find(s[i])==mp.end())
                {
                    mp[s[i]]=1;
                    cnt++;
                }
            }
        }
        if(cnt>1){
            cout<<"No"<<endl;
            continue;
        }
        if(flag1){
            cout<<"Yes"<<endl;
            continue;
        }
        for(int i=1;i<m;i++)
        {
            if(t[i]==t[i-1])
            {
                flag2=0;
                break;
            }
        }
        if(t[0]!=t[m-1])
            flag2=0;
        if(flag2==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(mp.begin()->first==t[0]){
            cout<<"No"<<endl;
            continue;
        }
        else{
            cout<<"Yes"<<endl;
            continue;
        }

    }
    return 0;
}
