#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
string s;
queue<int>q;
stack<int>st;
int a[N];
void solve(){
	int n;
	cin>>n;
	cin>>s;
	s="p"+s;
	int cnt = 0;
    int ans = 0;
	for(int i=n;i>0;){
		while(s[i]=='1'&&i>0){
			q.push(i);
			i--;
		}
		while(s[i]=='0'&&i>0){
			st.push(i);
			i--;
		}		
		while((!q.empty()&&!st.empty())){
			ans+=st.top();
			st.pop();
			q.pop();
		}
		while(!st.empty()){
			ans+=st.top();
			st.pop();
		}	
	}
	cnt=0;
	while(!q.empty()){
		a[++cnt]=q.front();
		q.pop();
	}
	for(int i=cnt;i>=cnt/2+1;i--)
        ans+=a[i];
	cout<<ans<<endl;
}
signed main(){
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}