#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    for(int i=l-2;i>=0;i--)
        s+=s[i];
    long long n=0;
    for(int i=0;i<s.length();i++)
        n = n*10+s[i]-'0';
    int flag=0;
    //cout<<n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag)cout<<"noprime\n";
    else cout<<"prime\n";
    return 0;
}