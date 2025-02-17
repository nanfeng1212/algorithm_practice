#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        int flag = 1;
        string ss="",ss1="";
        for(int i = 0; i < n; i++){
            ss+='#';
            ss1+='.';
        }
        if(a==ss&&(b!=ss&&b!=ss1))flag=0;
        if(b==ss&&(a!=ss&&a!=ss1))flag=0;
        if(!flag){
            cout << "No" << endl;
            continue;
        }
        if(a==ss||a==ss1){
            cout << "Yes" << endl;
            cout << a << endl;
            for(int i=2;i<=7;i++)cout << b << endl;
            continue;
        }
        string s[8];
        for(int i=1;i<=7;i++)s[i]="";
        for(int i=0;i<n;i++){
            s[1] += a[i];
            s[7] += b[i];
            if(a[i]=='#')s[2] += '.';
            else s[2] += '#';
            if(b[i]=='.')s[6] += '#';
            else s[6] += '.';
        }
        int p=-1,q=-1;
        for(int i=0;i<n;i++){
            if(s[2][i]=='.'){
                if(i==0){
                    if(s[2][i+1]=='#'){
                        p=i;
                        break;
                    }
                }
                else if(i==n-1){
                    if(s[2][i-1]=='#'){
                        p=i;
                        break;
                    }
                }
                else{
                    if(s[2][i-1]=='#'||s[2][i+1]=='#'){
                        p=i;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s[6][i]=='.'){
                if(i==0){
                    if(s[6][i+1]=='#'){
                        q=i;
                        break;
                    }
                }
                else if(i==n-1){
                    if(s[6][i-1]=='#'){
                        q=i;
                        break;
                    }
                }
                else{
                    if(s[6][i-1]=='#'||s[6][i+1]=='#'){
                        q=i;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i==p)s[3]+='#';
            else s[3]+='.';
            if(i==q)s[5]+='#';
            else s[5]+='.';
            s[4]+='.';
        }
        int minn = min(p,q);
        int maxx = max(p,q);
        if(minn==maxx)s[4][p]='#';
        else if(minn+1==maxx)s[4][p]='#';
        else{
            for(int i=minn+1;i<maxx;i++)s[4][i]='#';
        }
        cout << "Yes"<<endl;
        for(int i=1;i<=7;i++)cout << s[i] << endl;
    }   
}