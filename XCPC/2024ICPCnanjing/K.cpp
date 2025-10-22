#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k,w;
        cin >> n >> m >> k >> w;
        vector<int>a(n+1);
        vector<int>b(m+2);
        b[0]=0;
        b[m+1]=w+1;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=m;i++){
            cin >> b[i];
        }
        sort(a.begin()+1,a.end());
        sort(b.begin(),b.end());
        int flag = 0;
        int i=1;
        vector<int>ans;
        vector<int>res;
        while(i<=n){
            res.clear();
            int j = lower_bound(b.begin(),b.end(),a[i])-b.begin();
            int l = b[j-1],r=b[j];
            int f = i;
            int p=0,q=0;
            while(a[f]<r&&f<=n){
                if(q<a[f]){
                    p=a[f],q=a[f]+k-1;
                    res.push_back(p);
                }
                f++;
            }
            q=res.size()-1;
            int pos = r;
            while(q>=0){
                if(res[q]+k-1>=pos){
                    pos = pos-k;
                    res[q]=pos;
                    if(pos<=l){
                        flag=1;
                        break;
                    }
                }
                else break;
                q--;
            }
            for(auto p:res){
                ans.push_back(p);
            }
            i=f;
            if(flag)break;
        }
        if(flag){
            cout << -1 << endl;
        }
        else{
            cout << ans.size() << endl;
            for(auto i:ans)cout << i << ' ';
            cout << endl;
        }
    }
}
