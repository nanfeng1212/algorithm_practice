#include <bits/stdc++.h>
using namespace std;


int c[710][710];
int cnt[1000010];
int ans[710][710];
int sum;
int main() {
	int n, m, k;
    cin >> n >> m >> k;
	for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) 
            cin >> c[i][j];
	for(int i=1; i<=k; i++) 
        for(int j=1; j<=k; j++){
            if(cnt[c[i][j]]++ == 1)sum++;
        }
	ans[1][1] = sum;
    int x=1, y=1;
	while(x <= n-k+1){
		while(y <= n-k) {	
            y++;
			for(int i=x; i<x+k; i++) 
            {
                if(cnt[c[i][y-1]]-- == 2)sum--;
                if(cnt[c[i][y+k-1]]++ ==1)sum++;
            }
			ans[x][y] = sum;
		}

		if(x > n-k) 
            break;
        x++;
		for(int i=y; i<y+k; i++){
            if(cnt[c[x-1][i]]-- == 2)sum--;
            if(cnt[c[x+k-1][i]]++ ==1)sum++;
        }
		ans[x][y] = sum;

		while(y >= 2){
            y --;
			for(int i=x; i<x+k; i++){
                if(cnt[c[i][y]]++ == 1)sum++;
                if(cnt[c[i][y+k]]-- ==2)sum--;
            }
            ans[x][y] = sum;
		}
		if(x > n-k)
            break;
        x++;
		for(int i=y; i<y+k; i++){
            if(cnt[c[x-1][i]]-- == 2)sum--;
            if(cnt[c[x+k-1][i]]++ ==1)sum++;
        }
        ans[x][y] = sum;
	}
	while(m --){
		int x, y;
        cin >> x >> y;
		cout << ans[x][y] << endl;
	}
	return 0;
}

