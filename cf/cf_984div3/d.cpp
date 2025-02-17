#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
int n,k;
int main() {
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=m;j++)
            a[i][j] = s[j-1];
    }
    int p=n,q=m;
    long long ans = 0;
    while((p>=1&&q>=1)&&p*q>=4){
        vector<char>v;
        v.clear();
        for(int i=(m-q)/2+1;i<=(m-q)/2+q;i++)v.push_back(a[(n-p)/2+1][i]);
        for(int i=(n-p)/2+2;i<=(n-p)/2+p;i++)v.push_back(a[i][(m-q)/2+q]);
        for(int i=(m-q)/2+q-1;i>=(m-q)/2+1;i--)v.push_back(a[(n-p)/2+p][i]);
        for(int i=(n-p)/2+p-1;i>(n-p)/2+1;i--)v.push_back(a[i][(m-q)/2+1]);
        v.push_back(a[(n-p)/2+1][(m-q)/2+1]);
        v.push_back(a[(n-p)/2+1][(m-q)/2+2]);
        if((m-q)/2+3<=(m-q)/2+q)v.push_back(a[(n-p)/2+1][(m-q)/2+3]);
        else{
            v.push_back(a[(n-p)/2+2][(m-q)/2+q]);
        }
        for(int i=0;i<v.size()-3;i++)
            if((v[i]=='1'&&v[i+1]=='5')&&(v[i+2]=='4'&&v[i+3]=='3'))ans++;
        p -= 2;
        q -= 2;
    }
    cout << ans << endl;
  }
  return 0;
}
