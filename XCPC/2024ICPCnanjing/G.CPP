#include<bits/stdc++.h>
#define BoBoowen ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
vector<int> edge[N];
int siz[N];
int rt;
int ma[N];
int st[N];
int now = 1;
bool cmp(int a, int b)
{
    return siz[a] > siz[b];
}
int cnt = 0;
void dfs(int now, int fa, int tot)
{
    siz[now] = 1;
    ma[now] = 0;
    for (auto it : edge[now])
    {
        if (it == fa || st[it] == 1)
        {
            continue;
        }
        dfs(it, now, tot);
        siz[now] += siz[it];
        ma[now] = max(ma[now], siz[it]);
    }
    ma[now] = max(ma[now], tot - siz[now]);
    if (ma[now] < ma[rt])
    {
        rt = now;
    }
}
void dfsz(int now, int fa)
{
    siz[now] = 1;
    for (auto it : edge[now])
    {
        if (it == fa || st[it] == 1)
            continue;
        dfsz(it, now);
        siz[now] += siz[it];
    }
}
void dfs1(int now, int fa)
{

    vector<int> a;
    st[now] = 1;
    for (auto it : edge[now])
    {
        if (it == fa || st[it] == 1)
        {
            continue;
        }
        a.push_back(it);
    }
    if (a.size() == 0)
    {
        cout << "! " << now << "\n";
    }
    if (a.size() == 1)
    {

        cout << "? " << a[0] << " " << now << "\n";

        cnt++;
        int t;
        cin >> t;
        if (t == 0)
        {
            cout << "! " << a[0] << "\n";
        }
        else
            cout << "! " << now << "\n";
    }
    else if (a.size() == 2)
    {
        cout << "? " << a[0] << " " << a[1] << "\n";

        cnt++;
        int t;
        cin >> t;
        if (t == 0)
        {
            rt = 0;
            dfs(a[0], now, siz[a[0]]);
            dfsz(rt, now);
            dfs1(rt, now);
        }
        else if (t == 1)
        {
            cout << "! " << now << "\n";
            fflush(stdout);
        }
        else
        {
            rt = 0;
            dfs(a[1], now, siz[a[1]]);
            dfsz(rt, now);
            dfs1(rt, now);
        }
    }
    else if (a.size() == 3)
    {

        sort(a.begin(), a.end(), cmp);
        cout << "? " << a[0] << " " << a[1] << "\n";

        cnt++;

        int t;
        cin >> t;
        if (t == 0)
        {
            rt = 0;
            dfs(a[0], now, siz[a[0]]);
            dfsz(rt, now);
            dfs1(rt, now);
        }
        else if (t == 1)
        {
            rt = 0;
            st[now] = 0;
            st[a[0]] = 1;
            st[a[1]] = 1;
            dfs(now, fa, siz[a[2]] + 1);

            dfsz(rt, 0);
            dfs1(rt, 0);
        }
        else
        {
            rt = 0;
            dfs(a[1], now, siz[a[1]]);
            dfsz(rt, now);
            dfs1(rt, now);
        }
    }
}

signed main()
{

    int T = 1;
    cin >> T;
    while (T--)
    {
        now = 0;
        ma[0] = 1e9 + 7;
        int n;
        cin >> n;
        rt = 0;
        for (int i = 0; i <= n; i++)
        {
            edge[i].clear();
            st[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int now, it;
            cin >> now >> it;
            if (now != 0)
            {
                edge[i].push_back(now);
                edge[now].push_back(i);
            }
            if (it != 0)
            {
                edge[i].push_back(it);
                edge[it].push_back(i);
            }
        }
        dfs(1, 0, n);

        dfsz(rt, 0);
        dfs1(rt, 0);

        cnt = 0;
    }
    return 0;
}
