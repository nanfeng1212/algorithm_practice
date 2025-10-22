#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll n){
	if(n<=1) return n;
	if(n&1) return f(n>>1)+1;
	return f(n>>1);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		cout<<f(n)<<' '<<((1ll<<f(n))-1)<<endl;//((1ll<<f(n))-1)就是把数字转成01串的过程
	}
	return 0;}