#include<bits/stdc++.h>
using namespace std;


int main() {
	int b,c,l,r;
	cin >> b >> c >> l >> r;
	int ans = 0;
	if (l%2) l++;
	for (int i=l; i<=r; i+=2) {
		ans += i*i + b*i + c;
	}
	ans *= 2;
	cout << ans;
	return 0;
} 
