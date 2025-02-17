#include<bits/stdc++.h>
using namespace std;
int n,p;
vector<int>edge[1000000];
int w[210][210];
int out[210];
int vis[210];
struct ty{
    int c,u;
}a[1010];
int main()
{
    queue<int>q;
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].c >> a[i].u;
        if(a[i].c>0)q.push(i),vis[i]=1;
        else a[i].c -= a[i].u;
    }
    for(int i = 1; i <= p; i++)
    {
        int x,y,v;
        cin >> x >> y >>v;
        w[x][y] = v;
        out[x]++;
        edge[x].push_back(y);
    }
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        if(a[i].c <= 0)continue;
        for(int j = 0; j < edge[i].size(); j++)
        {
            int k = edge[i][j];
            a[k].c += w[i][k]*a[i].c;
            if(vis[k])continue;
            q.push(k);vis[k]=1;
        }
    }
    int flag=1;
    for(int i = 1; i <= n; i++)
    {
        if(out[i] == 0 && a[i].c > 0)
        {
            cout << i << " " << a[i].c <<endl;
            flag=0;
        }
    }
    if(flag)cout<<"NULL"<<endl;
    return 0;   
}