#include <bits/stdc++.h>
using namespace std;

int c,n;
struct ty{
    int cnt;
    int idx;
    bool operator<(const ty &a) const
    {
        return cnt<a.cnt;
    }
};
int ans[5010];
int sum[500010];
map<int,string>mp;
priority_queue<ty>q;
int main() {
    cin >> n >> c;
    int p = 0;
    for (int i=1; i<=n; i++) {
        string s;
        int k;
        cin >> s >> k;
        mp[i] = s;
        ans[i] = k/c;
        p += k/c;
        if (k%c==0) continue;
        ans[i]++;
        q.push({k%c,i});
    }
    int pp = 0;
    while (!q.empty()) {
        ty a = q.top();
        q.pop();
        int flag = 1;
        for (int i=1; i<=pp; i++) {
            if (c-sum[i]>=a.cnt) {
                sum[i] += a.cnt;
                flag = 0;
                break;
            }
        }
        if (flag) {
            pp++;
            sum[pp] = a.cnt;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << mp[i] << ' ' << ans[i] << endl;
    }
    cout << p+pp << endl;
}
/*
#include <bits/stdc++.h>
using namespace std;

int c,n;
struct ty{
    int cnt;
    int idx;
    bool operator<(const ty &a) const
    {
        return cnt<a.cnt;
    }
};
int ans[5010];
int sum[500010];
map<int,string>mp;
priority_queue<ty>q;
int main() {
    cin >> n >> c;
    for (int i=1; i<=n; i++) {
        string s;
        int k;
        cin >> s >> k;
        mp[i] = s;
        q.push({k,i});
    }
    int p = 0;
    while (!q.empty()) {
        ty a = q.top();
        q.pop();
        if (a.cnt>=c) {
            p++;
            ans[a.idx]++;
            sum[p] = c;
            a.cnt -= c;
            if (a.cnt!=0) {
                q.push({a});
            }
        }
        else if (a.cnt<c) {
            int flag = 1;
            for (int i=1; i<=p; i++) {
                if (c-sum[i]>=a.cnt) {
                    sum[i] += a.cnt;
                    a.cnt = 0;
                    flag = 0;
                    ans[a.idx]++;
                    break;
                }
            }
            if (flag) {
                p++;
                sum[p] = a.cnt;
                ans[a.idx]++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << mp[i] << ' ' << ans[i] << endl;
    }
    cout << p << endl;
}
*/