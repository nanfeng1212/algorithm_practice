#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> mul(vector<int>a,vector<int>b) {
    vector<int>ans(a.size()+b.size(),0);
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<b.size(); j++) {
            ans[i+j] += a[i]*b[j];
        }
    }
    for (int i=0; i<ans.size()-1; i++) {
        ans[i+1] += ans[i]/10;
        ans[i] %= 10;
    }
    while (ans.size()&&ans[ans.size()-1]==0)ans.pop_back();
    return ans;
}
vector<int> sub(vector<int>a, vector<int>b) {
    int flag = 0;
    for (int i=0; i<a.size(); i++) {
        a[i] -= flag;
        if (i<b.size()) {
            a[i] -= b[i];
        }
        if (a[i]<0) {
            flag = 1;
            a[i] += 10;
        }
        else flag = 0;
    }
    while (a.size()&&a[a.size()-1]==0)a.pop_back();
    return a;
}
int main()
{
  // 请在此输入您的代码
    string a,b;
    cin >> a >> b;
    if (a[0]=='-') a.assign(a,1,a.size()-1);
    if (b[0]=='-') b.assign(b,1,b.size()-1);
    if ((a<b&&a.length()==b.length())||a.length()<b.length()) {
        string tmp = a;
        a = b;
        b = tmp;
        cout << '-';
    }
    vector<int>a1,b1;
    for (int i=a.length()-1; i>=0; i--) a1.push_back(a[i]-'0');
    for (int i=b.length()-1; i>=0; i--) b1.push_back(b[i]-'0');
    vector<int> ans = sub(mul(a1,a1),mul(b1,b1));
    for (int i=ans.size()-1; i>=0; i--)cout << ans[i];
    return 0;
}