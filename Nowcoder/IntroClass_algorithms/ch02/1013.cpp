#include<iostream>
#include<string>
using namespace std;
string s; int n;
string h;
void fun(int l, int r)
{
    if (l > r)return;
    if (l == r) {
       // cout << 2 << endl;
        if (s[l] == '0') {
            //cout << 3 << endl;
            h += "B";
        }
        else  h += "I";
        return;
    }
    int mid = (l + r) / 2;
    fun(l, mid);
    fun(mid + 1, r);
    char a = s[l]; int flag = 1;
    for (int i = l + 1; i <= r; i++)
    {
        if (s[i] != s[l]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        //cout << 1 << endl;
        if (a == '0')h += "B";
        else h += "I";
    }
    else h += "F";
    return;
}


int main()
{
    cin >> n;
    cin >> s;
    int l = s.length() - 1;
    fun(0, l);
    int i = 0;
    while (h[i])
    {
        cout << h[i];
        i++;
    }
    return 0;
}
