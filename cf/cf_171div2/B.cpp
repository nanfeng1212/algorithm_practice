#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3 + 3;

int n;
int a[N];

bool check(int x){
	if(n%2){
		int ans = 0;
		for(int i = 1;i<=n;i++){
			vector<int> b(N+1);
			for(int j = 1;j<=n;j++) b[j] = a[j];
			b.erase(b.begin() + i);
			for(int j = 2;j<=b.size();j+=2){
				if(b[j] - b[j-1] > x){
					ans++;
					break;
				}
			}
		}
		if(ans == n)
            return false;
		else 
            return true;
	} 
    else{
		for(int i = 2;i<=n;i+=2){
			if(a[i] - a[i-1] > x)
                return false;
		}
		return true;
	}
}

void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	int l = 1,r = 1E18,m;
	while(l<r){
		m = l + r >> 1;
		if(check(m)) r=m;
		else l=m+1;
	}	
	cout<<l<<endl;
}

signed main(){
	int T; 
    cin>>T; 
    while(T--)
	    solve();
	return 0;
}
