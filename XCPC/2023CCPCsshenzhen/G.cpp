#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll h[310][60010];
ll ha[60010];
ll P[60010];
int main(){
    int n,q,m,k;
    cin >> n >> q >> m >> k;
    P[0] = 1;
    for(int i=1;i<=m;i++){
        P[i] = P[i-1]*131;
    }
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=0;j<s.size();j++)
            h[i][j+1] = h[i][j]*131+s[j];
    }
    for(int i=1;i<=q;i++)
    {
        cin >> s;
        int ans = 0;
        for(int j=0;j<s.size();j++)
            ha[j+1] = ha[j]*131+s[j];
        for(int j=1;j<=n;j++){
            int p = 1;
            int cnt = 0;
            while(p<=m&&cnt<=k){
                int l=p,r=m;
                while(l<=r){
                    int mid = (l+r)/2;
                    ll x = h[j][mid]-h[j][l-1]*P[mid-l+1];
                    ll y = ha[mid]-ha[l-1]*P[mid-l+1];
                    if(x==y)l = mid+1;
                    else r = mid-1; 
                    //cout << 111111111 << endl;
                }
                if(l<=m){
                    cnt++;
                }
                p = l+1;
            }
            if(cnt<=k)ans++;
        }
        cout << ans << endl;
    }
}