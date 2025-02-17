#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        string s="",ans="Yes";
        s += 'L';
        string d;
        cin>>d;
        s+=d;
        s+='L';
        int count=0,check=0;
        int count2=1;
        for(int i = 0; i <= n; i++) {
            if(s[i]=='L')
                count2=m-1;
            else if(count2>0)
                count2--;
            else if(count2==0&&s[i]=='W')
                k--;
            else{
                ans="No";
                break; 
            }
            if(k<0 || count2<0){
                ans="No";
                break;
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}