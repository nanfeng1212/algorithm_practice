#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const double eps = 1e-5;

int n, k;
double s[N], c[N], val[N];

bool check(double D) {
	double sum = 0;
	for(int i = 1; i <= n; i++)	val[i] = s[i] * (c[i] - D);
	sort(val+1, val+1+n, [](double x, double y) {
		return x > y;
	});
	for(int i = 1; i <= n - k; i++)	sum += val[i];
	if(sum >= 0)	return true;
	else	return false;
}

signed main() {
	cin>>n>>k;
	for(int i = 1; i <= n; i++)	cin>>s[i];
	for(int i = 1; i <= n; i++)	cin>>c[i];
	double l = 0, r = 1000.0;
	while(r - l > eps) {
		double mid = (l + r) / 2.0;
		if(check(mid))	l = mid;
		else	r = mid;
	}
	cout<<setprecision(12)<<fixed<<l;
	return 0;
}