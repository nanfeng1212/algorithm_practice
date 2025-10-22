#include<bits/stdc++.h>
using namespace std;

map<string,int>sex;
map<string,string>fa;
bool check(string a, string b) {
    map<string,int>num;
    for (int i=1; a!=""; i++)
    {
        num[a] = i;
        a = fa[a];
    }
    
    for (int i=1; b!=""; i++)
    {
        if (num[b])
        {
            if (num[b]>=5 && i>=5)
                return true;
            else 
                return false;
        }
        b = fa[b];
    }
    return true;
}
int main() {
    int n,m;
    cin >> n;
    string id, x;
    for(int i=1; i<=n; i++) {
        cin>> id >> x;
        if(x.back() == 'm')
            sex[id] = 1;
        else if(x.back() == 'f')
            sex[id] = 0;
        else if(x.substr(x.size()-4) == "sson")
        {
            sex[id] = 1;
            fa[id] = x.substr(0, x.size()-4);
        }
        else
        {
            sex[id] = 0;
            fa[id] = x.substr(0, x.size()-7);
        }
    }
    cin >> m;
    while (m--) {
        string m1, x1, m2, x2;
        cin >> m1 >> x1 >> m2 >> x2;
        if (sex.count(m1)==0 || sex.count(m2)==0)
            cout << "NA" << endl;
        else if (sex[m1]==sex[m2])
            cout << "Whatever" << endl;
        else if (check(m1,m2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
