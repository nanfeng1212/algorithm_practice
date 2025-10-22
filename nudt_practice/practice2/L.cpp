#include <bits/stdc++.h>
using namespace std;

struct ty{
    int t;
    int idx;
};

bool cmp(ty x, ty y){
    return x.t < y.t;
}
vector<ty>ans1;
vector<ty>ans2;
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(c&&d){
            if(a<b)ans1.push_back({a,i});
            else ans2.push_back({b,i});
        }
        else if(c)
            ans1.push_back({a,i});
        else
            ans2.push_back({b,i});
    }
    sort(ans1.begin(),ans1.end(),cmp);
    sort(ans2.begin(),ans2.end(),cmp);

    cout << ans1.size() << ' ';
    for(auto i:ans1){
        cout << i.idx << ' ';
    }
    cout << '\n';
    
    cout << ans2.size() << ' ';
    for(auto i:ans2){
        cout << i.idx << ' ';
    }
    cout << endl;
    return 0;
}