#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
string s;
string ss="";
int p1,p2,p3;
string fun(char a, char b)
{
    if (b - a == 1)return "";
    if (!((isalpha(a) && isalpha(b) && a < b) || (isdigit(b) && isdigit(a) && a < b)))return "-";
    string ans = "";
    for (char q = a + 1; q < b; q++)
        for(int i=1;i<=p2;i++)
        {
            if (p1 == 1)ans += q;
            if (p1 == 2)
            {
                if(isalpha(a))ans += q + 'A' - 'a';
                else ans+=q;
            }
            if (p1 == 3)ans += '*';
        }
    if (p3 == 2)reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    scanf("%d%d%d",&p1,&p2,&p3);
    cin>>s;
    int l=s.length();
    ss+=s[0];
    int i=1;
    while(i<l-1)
    {
        if(s[i]=='-')ss+=fun(s[i-1],s[i+1]);
        else ss+=s[i];
        i++;
    }
    if(l>1)ss+=s[l-1];
    cout<<ss;
    return 0;
    
}