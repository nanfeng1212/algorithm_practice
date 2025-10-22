#include<bits/stdc++.h>
using namespace std;

int in[100010];
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int a[100010];
pair<int,int>b[100010];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        in[x]++;
        in[y]++;
    }
    for(int i=1;i<=n;i++){
        b[i] = {i,a[i]};
    }
    sort(b+1,b+1+n,cmp);
    int ans;
    if(in[b[n].first]!=1)ans=a[b[n].first];
    else ans=a[b[n-1].first];
    if(n==1)cout << a[1] << endl;
    else cout << ans << endl;
    return 0;
}