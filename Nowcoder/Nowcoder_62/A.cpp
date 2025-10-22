#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<char>a;
    for(int i=0;i<5;i++)
    {
        char c;
        cin>>c;
        if(i==1)cout<<c;
        else a.push_back(c);
    }
    for(auto i:a)cout<<i;
}