#include<bits/stdc++.h>
using namespace std;
int x[10010];
int y[10010];
int x2[10010];
int y2[10010];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> x[i] >> y[i] >> x2[i] >>y2[i];
    int p,q;
    cin >> p >> q;
    for(int i=n;i>=1;i--)
    {
        if(x[i]<=p&&x[i]+x2[i]>=p&&y[i]<=q&&y[i]+y2[i]>=q){
            cout << i;
            return 0;
        }
    }
    cout <<-1;
    return 0;
}