#include<iostream>
#include<cmath>
const int N = 65536;
using namespace std;
string s;
bool sum;
int f[N];
int fun1(int l, int r)
{
    int k = 0;
    for (int i = l; i <= r; i++)
        k = k * 10 + s[i] - '0';
    return k;
}
int power(int x, int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, (y / 2));
    if (y % 2 == 0)
        return (temp * temp) % N;
    else
    {
        if (y > 0)
            return (x * temp * temp) % N;
        else
            return ((temp * temp) / x) % N;
    }
}
int fun(int l, int r)
{
    int pos1 = -1, pos3 = -1, pos2 = -1, pos4 = -1;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '+' || s[i] == '-')pos1 = i;
        if (s[i] == '*' || s[i] == '/')pos2 = i;
        if (s[i] == '^')pos3 = i;
        if (s[i] == '!')pos4 = i;
    }
    //cout<<pos1<<' '<<pos2<<' '<<pos3<<' '<<pos4<<endl;
    if (pos1 == -1 && pos2 == -1 && pos3 == -1 && pos4 == -1)
        return fun1(l, r);
    else if (pos1 != -1)
    {
        if (s[pos1] == '+') return (fun(l, pos1 - 1) + fun(pos1 + 1, r)) % N;
        else  return (fun(l, pos1 - 1) - fun(pos1 + 1, r)) % N;
    }
    else if (pos2 != -1)
    {
        if (s[pos2] == '*') return (fun(l, pos2 - 1) * fun(pos2 + 1, r)) % N;
        else
        {
            if (fun(pos2 + 1, r) == 0) {
                sum = 1;
            }
            else 
            {
                return (fun(l, pos2 - 1) / fun(pos2 + 1, r)) % N;
            }
        }
    }
    else if (pos3 != -1)
    {
        return power(fun(l, pos3 - 1), fun(pos3 + 1, r));
    }
    else if (pos4 != -1) {
        int a = fun(l, pos4 - 1);
        return f[a];
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % N;
    while (t--)
    {
        cin >> s;
        sum = 0;
        int p = fun(0, s.size() - 1);
        if(!sum) cout << p << endl;
        else  cout << "ArithmeticException" << endl;
    }
    return 0;
}