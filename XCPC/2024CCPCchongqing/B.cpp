#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int ppmax;
        cin >> ppmax;
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        int fz = 300*a+300*b+200*c+100*d+50*e+0*f;
        int fm = 300*(a+b+c+d+e+f);
        double acc = double(fz)/double(fm)*100;
        double pp = max(double(0),double(320*a+300*b+200*c+100*d+50*e+0*f)/double(320*(a+b+c+d+e+f))*100-80)/100*5*ppmax;
        int p;
        pp+=1e-6;
        if(pp-(int)pp>=(double)0.5)p=(int)pp+1;
        else p = (int)pp;
        printf("%.2f%% %d\n",acc,p);
    }
}