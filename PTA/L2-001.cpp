#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, s, d;
int jyd[N];
int len[N][N];
int num[N];
int mjyd[N];
int pre[N];
int dist[N];
int st[N];
void dfs()
{
    memset(st, 0, sizeof(st));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    memset(num, 0, sizeof(num));
    num[s] = 1;
    memset(mjyd, 0, sizeof(mjyd));
    mjyd[s] = jyd[s];
    for(int i = 0; i < n - 1; i++){
        int t = -1;
        for(int j = 0; j < n; j++){
            if(st[j] == 0 && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        for(int j = 0; j < n; j++){
            if(dist[t] + len[t][j] < dist[j]){
                dist[j] = dist[t] + len[t][j];
                num[j] = num[t];
                mjyd[j] = mjyd[t] + jyd[j];
                pre[j] = t;
            }
            else if(dist[t] + len[t][j] == dist[j]){
                num[j] += num[t];
                if(mjyd[t] + jyd[j] > mjyd[j]){
                    mjyd[j] = mjyd[t] + jyd[j];
                    pre[j] = t;
                }
            }
        }

        st[t] = 1;
    }
}

void print(int ss, int tt)
{
    if(ss == tt){
        cout << ss << " ";
        return;
    }
    print(ss, pre[tt]);
    cout << tt << " ";
}


int main()
{
    cin >> n >> m >> s >> d;
    for(int i = 0; i < n; i++)  cin >> jyd[i];
    memset(len, 0x3f, sizeof(len));
    int aa, bb, cc;
    for(int i = 0; i < m; i++){
        cin >> aa >> bb >> cc;
        len[aa][bb] = len[bb][aa] = cc;
    }
    dfs();
    cout << num[d] << " " << mjyd[d] << endl;
    print(s, pre[d]);
    cout << d << endl;
    return 0;
}