#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100010];
int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        int ans = 1;
        int l = 1, r = a[0];
        while (l<=r) {
            int mid = (l+r)/2;
            if (a[mid]>k) r = mid-1;
            else l = mid+1;
        }
        r+=1;
        if (r>a[0]) {
            a[0]++;
            a[a[0]] = k;
        }
        else a[r] = k;
    }
    cout << a[0];
}