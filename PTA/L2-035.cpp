#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
int h[100];
int cnt = 1;
void dfs(int x) {
    if (x>n) return;
    dfs(2*x);
    dfs(2*x+1);
    a[x] = h[cnt++];
}
int main() {
   cin >> n;
   for (int i=1; i<=n; i++) cin >> h[i];
   dfs(1);
   cout << a[1];
   for (int i=2; i<=n; i++) cout << ' ' <<a[i];
}