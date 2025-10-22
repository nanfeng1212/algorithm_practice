#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
struct edge { 
    int to;
    int cost; 
};
vector<edge> G[2010];
int n, m, k, ds;
int d[2010];
struct node {
    int d, no, tot;
    bool operator < (const node & a ) const {
        if(d != a.d) return d > a.d;
        return tot == a.tot ? no < a.no : tot < a.tot;
    }
};
vector<node> res;
void dijkstra(int s) {
    memset(d,0x3f3f3f,sizeof(d));
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P{0, s});
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v]<p.first) 
            continue;
        for(edge e:G[v]) 
            if(d[e.to]>d[v]+e.cost) {
                d[e.to] = d[v]+e.cost;
                que.push(P{d[e.to],e.to});
            }
    }
    int _d = 0x3f3f3f, _tot = 0;
    for(int i=1; i<=n; i++) {
        if(d[i]>ds) 
            return;
        _d = min(_d, d[i]);
        _tot += d[i];	
    }
    res.push_back(node{_d, s-n, _tot});
}

#define getno(s) (s[0] == 'G' ? stoi(s.substr(1))+n : stoi(s))
int main() {
    cin >> n >> m >> k >> ds;
    for(int i = 0; i < k; i++) {
        string s1, s2;
        int dis;
        cin >> s1 >> s2 >> dis;
        int x = getno(s1), y = getno(s2);
        G[x].push_back(edge{y, dis});
        G[y].push_back(edge{x, dis});
    }
    for(int i=1; i<=m; i++) dijkstra(i+n);
    if(res.size()==0) { 
        cout << "No Solution";
        return 0;
    }
    sort(res.begin(), res.end());
    printf("G%d\n%.1f %.1f", res[0].no, 1.0 * res[0].d, res[0].tot * 1.0 / n);
    return 0;
}
