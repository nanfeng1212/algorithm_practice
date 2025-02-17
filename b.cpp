#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
struct ty{
	long long w,l,r;
}a[100010];
bool cmp(ty x, ty y){
	return x.w<y.w;
}
long long t[100010];
long long rt[100010];
long long wt[100010];
int main(){
	int T = 1; 
    while(T--)
	{
		cin >> n >> m;
		long long ans = 0;
		long long s = 0, cur = 0;
		for(int i=1; i<=n; i++){
			cin >> a[i].w >> a[i].l >> a[i].r;
		}
		sort(a+1, a+1+n, cmp);
		long long sum = 0;
		for(int i=1; i<=n; i++){
			t[i] = a[i].l;
			m -= a[i].l;
			sum += a[i].w * a[i].l;
		}
		ans = sum+m*a[n].w;
		for(int i=n; i>=1; i--){
			if(m>a[i].r-t[i]){
				m = m - a[i].r + t[i];
				sum += a[i].w*(a[i].r-t[i]);
				t[i] = a[i].r;
			}
			else{
				sum += a[i].w*m;
				t[i] += m;
				m = 0;
				break;		
			}
		}
		for(int i=n; i>=1; i--){
			rt[i] = rt[i+1] + a[i].r - t[i];
            wt[i] = wt[i+1] + a[i].w * (a[i].r - t[i]);
		}
		for(int i=n-1; i>=1; i--){
			long res = 0;
			long l = i+1, r = n;
			while(l<=r){
				long long mid = (l+r)/2;
				if(t[i]>=rt[mid]){
					r = mid-1;
				}
				else
					l = mid+1;
			}
			res = wt[l] - t[i]*a[i].w + (t[i]-rt[l])*a[l-1].w;
			ans = max(ans,sum+res);
		}
		cout << ans << endl;

	}
	return 0;
}
