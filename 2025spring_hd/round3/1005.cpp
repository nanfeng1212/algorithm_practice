#include<bits/stdc++.h>
using namespace std;

int a[300010];
int f[300010];
int find (int x) {
    if(f[x]==x) 
        return f[x];
    else return f[x]=find(f[x]);
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
  
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) f[i] = i;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            if (i+a[i]<=n){
                int f1 = find(i),f2 = find(i+a[i]);
                if (f1!=f2) {
                    f[f2] = f1;
                }
            }
            if(i-a[i]>=1) {
                int f1 = find(i), f2 = find(i-a[i]);
                if (f1!=f2) {
                    f[f2] = f1;
                }
            }
        }
        int ans = 0;
        for (int i=1; i<=n; i++) 
            if(find(i)==i) 
                ans++;
        cout << ans-1 << endl;

    }
    return 0;
  }