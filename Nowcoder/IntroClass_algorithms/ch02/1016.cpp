#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
char s[40];
int sum = 0;
int fun1(int l, int r)
{
    int i = l; int k = 0;
    while (i <= r) {
        k = k * 10 + s[i] - '0';
        i++;
    }
    return k;
}
int fun(int l, int r) {
    int pos1 = -1, pos2 = -1, pos3 = -1,cnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '(')cnt++;
        if (s[i] == ')')cnt--;
        if (cnt == 0)
        {
            if (s[i] == '+' || s[i] == '-')pos1 = i;
            if (s[i] == '*' || s[i] == '/')pos2 = i;
            if (s[i] == '^')pos3 = i;
        }
    }
    if (pos1 == -1 && pos2 == -1 && pos3 == -1)
    {
        if (cnt == 0 && s[l] == '(')return fun(l + 1, r - 1);
        if (cnt > 0 && s[l] == '(')return fun(l + 1, r);
        if (cnt < 0 && s[r] == ')')return fun(l, r - 1);
        return fun1(l, r);
    }
    if (pos1 != -1)
    {
        if (s[pos1] == '+')return fun(l, pos1 - 1) + fun(pos1 + 1, r);
        else return fun(l, pos1 - 1) - fun(pos1 + 1, r);
    }
    else if (pos2 != -1)
    {
        if (s[pos2] == '*')return fun(l, pos2 - 1) * fun(pos2 + 1, r);
        else return fun(l, pos2 - 1) / fun(pos2 + 1, r);
    }
    else if (pos3 != -1)
        if(s[pos3]=='^')return pow(fun(l, pos3 - 1), fun(pos3 + 1, r));
    return 0;
}
int main()
{
    cin >> s;
    int l = strlen(s) - 1;
    sum = fun(0, l);
    cout << sum;
    return 0;
}