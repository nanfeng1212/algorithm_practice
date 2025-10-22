#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,k;
long long ans;
int pos[1000010][2];
int d1[8]={1,1,0,-1,-1,-1,0,1};
int d2[8]={0,1,1,1,0,-1,-1,-1};
vector<int> changes;
unordered_map<int,map<int,int>> dirs[4];
void add(int x,int y,int id) {
    dirs[0][y][x] = id;
    dirs[1][y-x][x] = id;
    dirs[2][x][y] = id;
    dirs[3][y+x][x] = id;
}
void del(int x, int y) {
    dirs[0][y].erase(x);
    dirs[1][y-x].erase(x);
    dirs[2][x].erase(y);
    dirs[3][y+x].erase(x);
}
pair<int,int> nxt(int x, int y, int u, int v, int t) {
    int dx=x-u,dy=y-v;
    int new_dx=dx*d1[t]-dy*d2[t],new_dy=dx*d2[t]+dy*d1[t];
    if(t%2&&dx&&dy) new_dx/=2,new_dy/=2;
    return make_pair(u+new_dx,v+new_dy);
}

void checkDirectionUpdate(map<int,int>::iterator it,int pos_val) {
    if(abs(it->first-pos_val)==k) {
        changes.push_back(it->second);
    }
    else if(abs(it->first-pos_val)<k) {
        changes.clear();
        k=abs(it->first-pos_val);
        changes.push_back(it->second);
    }
    return;
}

void checkDirection(int dir_id,int locator,int pos_val) {
    if(dirs[dir_id].find(locator)!=dirs[dir_id].end())
    {
        auto it=dirs[dir_id][locator].upper_bound(pos_val);
        if(it!=dirs[dir_id][locator].end())
        {
            checkDirectionUpdate(it,pos_val);
        }
        it=dirs[dir_id][locator].lower_bound(pos_val);
        if(it!=dirs[dir_id][locator].begin())
        {
            it--;
            checkDirectionUpdate(it,pos_val);
        }
    }
    return;
}
void work(int u,int v,int t)
{
    k=2147483647;
    changes.clear();
    checkDirection(0, v, u);
    checkDirection(1, v-u, u);
    checkDirection(2, u, v);
    checkDirection(3, v+u, u);
    //k不能大于到(u,v)到边界的位置
    if(k<=min(min(u-1,n-u),min(v-1,m-v))) {
        for(auto id:changes)
        {
            int old_x=pos[id][0],old_y=pos[id][1];
            del(old_x,old_y);
        }
        for(auto id:changes)
        {
            int old_x=pos[id][0],old_y=pos[id][1];
            int new_x,new_y;
            tie(new_x,new_y)=nxt(old_x,old_y,u,v,t);
            pos[id][0]=new_x,pos[id][1]=new_y;
            add(new_x,new_y,id);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p >> q;
    for(int i=0; i<p; i++) {
        int x, y;
        cin >> x >> y;
        pos[i][0] = x;
        pos[i][1] = y;
        add(x, y, i);
    }
    for(int i=0; i<q;i++) {
        int u, v, t;
        cin >> u >> v >> t;
        work(u, v, t);
    }
    for(int id=0; id<p; id++) {
        ans ^= (id+1ll)*pos[id][0]+pos[id][1];
    }
    cout << ans << endl;
}
/*
in:
3 3 9 1
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
2 2 1

out:
20
*/
