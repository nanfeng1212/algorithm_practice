#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>ans;
signed main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long cnt;
        for(cnt=60;cnt>=0;cnt--){
            if(n&(1ll<<cnt)){
                break;
            }
        }
        ans.clear();
        for(long long i=cnt;i>=0;i--){
            long long l=1ll<<i;
            long long r = (1ll<<(i+1))-1;
            r = min(n,r);
            cout << "xor" << ' ' << l << ' ' << r << endl;
            cout.flush();
            long long f;
            cin >> f;
            if(f){
                if(l==r){
                    ans.push_back(l);
                    break;    
                }
                int res ;
                while(l<=r){
                    long long mid = (l+r)/2;
                    cout << "xor" << ' ' << l << ' ' << mid << endl;
                    cout.flush();
                    cin >> f;
                    if(f){
                        r = mid-1;
                        res = mid;
                    }
                    else{
                        l = mid+1;
                    }
                }
                ans.push_back(res);
                break;
            }  
        }
        long long l=1,r=n;
        long long num1=0,num2=0,num3=0;
        num1 = ans[0];
        if(num1==1)
            l = 2;
        else if(num1==n)
            r = n-1; 
        else{
            cout << "xor" << ' ' << 1 << ' ' << num1-1 << endl;
            cout.flush();
            long long f;
            cin >> f;
            if(f){
                l = 1;
                r = num1-1;
            }
            else{
                l = num1+1;
                r = n;
            }
        }
        int res = 1;
        while(l<=r){
            long long mid = (l+r)/2;
            cout << "xor" << ' ' << l << ' ' << mid << endl;
            cout.flush();
            long long f;
            cin >> f;
            if(f){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        ans.push_back(res);
        num1 = ans[0];
        num2 = ans[1];
        cout << "xor " << 1 << ' ' << n << endl;
        cout.flush();
        cin >> num3;
        num3 = num3^(num1^num2);
        cout << "ans" << ' ' << num1 << ' ' << num2 << ' ' << num3 << endl;
        cout.flush();
    }
}