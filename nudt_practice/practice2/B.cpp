#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[10];
int main(){
    int t;
    cin>>t;
    while(t--){
        ll ans = 0;
        for(int i=1; i<=5; i++)
            cin>>a[i];
        ll mid1 = min(a[1],a[5]);
        ll mid2 = min(a[2],a[4]);
        ll mid3 = a[3]/2;
        ans += mid1+mid2+mid3;
        a[1] -= mid1;
        a[5] -= mid1;
        a[2] -= mid2;
        a[4] -= mid2;
        a[3] -= mid3*2;
        if(a[5]){
            ll mid4 = min(a[5],a[2]+a[3]+a[4]);
            ans += mid4;
            a[5] -= mid4;
            if(a[2]>mid4)
                a[2] -= mid4;
            else{
                mid4 -= a[2];
                a[2] = 0;
                if(a[3]>mid4)
                    a[3] -= mid4;
                else{
                    mid4 -= a[3];
                    a[3] = 0;
                    if(a[4]>mid4)
                        a[4] -= mid4;
                    else{
                        mid4 -= a[4];
                        a[4]=0;
                    }
                }
            }
            if(a[5]){
                ans += a[5]/2;
                a[5] %= 2;
                a[1] += a[5];
                a[5] = 0;
            }
        }
        if(a[4]){
            ll mid5 = min(a[4],(a[1]+a[3])/2);
            ans += mid5;
            a[4] -= mid5;
            mid5 *= 2;
            if(a[1]>mid5)
                a[1] -= mid5;
            else{
                mid5 -= a[1];
                a[1] = 0;
                if(a[3]>mid5)
                    a[3] -= mid5;
                else {
                    mid5 -= a[3];
                    a[3] = 0;
                }
            }
            if(a[4]){
                ans += a[4]/3;
                a[4] %= 3;
                if(a[4]==2){
                    a[1]++;
                    a[4]--;
                    mid5 = min(a[4],(a[1]+a[3])/2);
                    ans += mid5;
                    a[4] -= mid5;
                    mid5 *= 2;
                    if(a[1]>mid5)
                        a[1] -= mid5;
                    else{
                        mid5 -= a[1];
                        a[1] = 0;
                        if(a[3]>mid5)
                            a[3] -= mid5;
                        else{
                            mid5 -= a[3];
                            a[3] = 0;
                        }
                    }
                }
                if(a[4]){
                    a[1]++;
                    a[4] = 0;
                }
            }
        }
        ans += (a[1]+a[2]*2+a[3]*3)/6;
        cout << ans << endl;
    }
    return 0;
}