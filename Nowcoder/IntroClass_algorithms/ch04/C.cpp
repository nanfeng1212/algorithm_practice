#include<bits/stdc++.h>
#include<stack>
using namespace std;
string s;
int main()
{
    cin>>s;
    int n=s.length();
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')k++;
        else {
            if(k==0){
                cout<<"Bad";
                return 0;
            }
            k--;
        }
    }
    if(k==0)cout<<"Good";
    else cout<<"Bad";
    return 0;
}