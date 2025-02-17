#include<iostream>
#include<string.h>
using namespace std;
int d;
int k = 0;
string s;
int a[40];
int main()
{
    memset(a, 0, sizeof(a));
    cin >> s;
    d = s.length();
    int l = 0, r = 25;
    int k = 0;
    for (int i = l; i <= r; i++)a[s[i] - 'a']++;
    while (l < d - 25 && r < d)
    {
        int flag = 1;
        for (int i = 0; i < 26; i++)
            if (a[i] == 0)
            {
                flag = 0;
                break;
            }
        if (flag)
        {
            if (k == 0)k = r - l + 1;
            else k = min(k, r - l + 1);
            a[s[l]-'a']--;
            l++;
        }
        else {
            r++;
            if(r<d)a[s[r] - 'a']++;
        }
    }
    cout << k << endl;
    return 0;
}