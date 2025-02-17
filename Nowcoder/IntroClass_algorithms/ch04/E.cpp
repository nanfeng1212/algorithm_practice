#include<iostream>
#include<stack>
using namespace std;
string s;
char c[110];
stack<char>ch;
int main()
{
    while(cin>>s)
    {
        int l=s.length();
        for(int i=0;i<l;i++)
        {
            if(ch.empty())ch.push(s[i]);
            else{
                int flag=1;
                while(!ch.empty()&&ch.top()==s[i])
                {
                    ch.pop();
                    if(s[i]=='o')s[i]='O';
                    else {
                        flag=0;
                        break;
                    }
                }
                if(flag)ch.push(s[i]);
            }
        }
        int j=0;
        while(!ch.empty())
        {
            c[j]=ch.top();
            j++;
            ch.pop();
        }
        for(j;j>=1;j--)
            cout<<c[j-1];
        cout<<endl;
    }
    return 0;
}