#include <bits/stdc++.h>
  
typedef int ll;
  
using namespace std;
  
const ll maxn = 1e5 + 7;
  
ll b[maxn],c[maxn];
vector<ll>a;
int main()
{
    ll n,x,m,to,s2;
    cin >> n >> s2;
    for(int i = 1; i <= n; i ++)
    {
        cin >> b[i];
    } 
     ll k = 1, s1 = s2;
     while(s2)
     {
        ll l,r;
        cin >> l >> r;
        m = r-l+1;
        if(s2 == s1)
        {
            for(int i = 1; i <= n; i ++)
            {
               a.insert(lower_bound(a.begin(),a.end(),b[i]),b[i]);
                 if(i >= m)
                {
                    c[k++] = a[a.size() / 2];
                  a.erase(lower_bound(a.begin(),a.end(),b[i - m + 1]));
                }
             }     
        }

        cout << c[l] <<endl;
        s2--;
     }
    
      
    return 0;
}