#include <bits/stdc++.h>
using namespace std;

long long d[25][2];
long long a[100010];
int main()
{
  // 请在此输入您的代码
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] ^= a[i-1];
    }
    long long ans = 0;
    for (int i=0; i<=20; i++) {
        for (int j=0; j<=n; j++) {
            if ((a[j]>>i)&1) d[i][1]++; 
            else d[i][0]++;
        }
        ans += d[i][0]*d[i][1]*pow(2,i);
    }
    cout << ans << endl;
  return 0;
}