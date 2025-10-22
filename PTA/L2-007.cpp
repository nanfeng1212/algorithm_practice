#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int fa[10010];
int cnt[10010];
double fcnt[10010];
double fc[10010];
map<int,int>mp;
int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}
struct ty{
    int id;
    int cnt;
    double fcnt;
    double fc;
};
bool cmp(ty x, ty y) {
    if(x.fc==y.fc)return x.id<y.id;
    else return x.fc>y.fc;
}
int main() {
    cin >> n;
    for (int i=0; i<=9999; i++){
        fa[i]=i;
        cnt[i]=1;
    }
    for (int i=1; i<=n; i++) {
        int a,b;
        cin >> a >> b;
        mp[a]=1;
        int f1 = find(a), f2;
        if (b!=-1){
            f2 = find(b);
            mp[b]=1;
            if(f1>f2)swap(f1,f2);
            if (f1!=f2) {
                //cout << cnt[f1] << ' ' << cnt[f2] << endl;
                fa[f2] = f1;
                cnt[f1] += cnt[f2];
                fcnt[f1] += fcnt[f2];
                fc[f1] += fc[f2];  
            }
        }
        cin >> b;
        if (b!=-1){
            mp[b]=1;
            f2 = find(b);
            if(f1>f2)swap(f1,f2);
            if (f1!=f2) {
                fa[f2] = f1;
                cnt[f1] += cnt[f2];
                fcnt[f1] += fcnt[f2];
                fc[f1] += fc[f2];  
            }
        }
        int k;
        cin >> k;
        while (k--) {
            cin >> b;
            mp[b]=1;
            f2 = find(b);
            if(f1>f2)swap(f1,f2);
            if (f1!=f2) {
                fa[f2] = f1;
                cnt[f1] += cnt[f2];
                fcnt[f1] += fcnt[f2];
                fc[f1] += fc[f2]; 
            }
        }
        double c,s;
        //cout << f1 << ' ' << fa[f1] << ' ' << cnt[f1] << endl;
        cin >> c >> s;
        fcnt[f1] += c;
        fc[f1] += s;
    }
    vector<ty>ans;
    ans.clear();
    for (int i=0; i<=9999; i++){
        if (mp[i]&&fa[i]==i){
            ans.push_back({i,cnt[i],fcnt[i]/double(cnt[i]),fc[i]/double(cnt[i])});
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    cout << ans.size() << '\n';
    for (auto i:ans){
        string s = to_string(i.id);
        while(s.length()<4)s = '0'+s;
        cout << s << ' ' << i.cnt << ' ';
        printf("%.3f %.3f\n",i.fcnt,i.fc);
    }
}