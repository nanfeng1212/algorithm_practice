#include<iostream>
#include<string.h>
using namespace std;
string a;
int n;
int s[1000010][40];
int main()
{
    memset(s, 0, sizeof(a));
    cin>>a;
    int l = a.length();
    for (int i = l-1; i >= 0; i--)
    {
        for(int j=0;j<26;j++)
            s[i][j] = s[i+1][j];
        s[i][a[i]-'a']=i+1;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        string s1;
        cin>>s1;
        int l1 = s1.length();
        bool flag = 1;
        int k=0;
        for (int j = 0; j < l1; j++)
        {
            if(s[k][s1[j]-'a'])k=s[k][s1[j]-'a'];
            else 
            {
                flag=0;
                break;
            }
        }
        if (flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;

}