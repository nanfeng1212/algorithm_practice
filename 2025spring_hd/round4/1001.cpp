#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Enemy {
    ll damage;
    int cnt;
    bool alive;
    ll h;
    int a;
    int id;
};

vector<Enemy> enemies;

struct CompareEnemy {
    bool operator()(int i, int j) const {
        ll rem_i = enemies[i].h - enemies[i].damage;
        ll rem_j = enemies[j].h - enemies[j].damage;
        if (rem_i != rem_j) return rem_i < rem_j;
        if (enemies[i].a != enemies[j].a) return enemies[i].a < enemies[j].a;
        return enemies[i].id < enemies[j].id;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        ll u, hq;
        cin >> n >> u >> k >> hq;

        enemies.clear();
        enemies.resize(n);
        multiset<int> a_multiset;
        for (int i = 0; i < n; ++i) {
            int a, h_i;
            cin >> a >> h_i;
            enemies[i] = {0, 0, true, h_i, a, i};
            a_multiset.insert(a);
        }

        set<int, CompareEnemy> candidate_set;
        for (int i = 0; i < n; ++i) {
            if (enemies[i].alive && enemies[i].cnt < k) {
                candidate_set.insert(i);
            }
        }

        int live_enemies = n;
        ll current_max_a = a_multiset.empty() ? 0 : *a_multiset.rbegin();

        while (!candidate_set.empty() && hq > 0 && live_enemies > 0) {
            auto it = candidate_set.begin();
            int idx = *it;
            candidate_set.erase(it);

            Enemy &e = enemies[idx];
            ll d = u >> e.cnt;
            e.damage += d;
            e.cnt++;

            if (e.damage >= e.h) {
                e.alive = false;
                live_enemies--;
                a_multiset.erase(a_multiset.find(e.a));
                current_max_a = a_multiset.empty() ? 0 : *a_multiset.rbegin();
            } else {
                if (e.cnt < k) {
                    candidate_set.insert(idx);
                }
            }
            if (live_enemies == 0) break;
            if (current_max_a == 0) break;
            hq -= current_max_a;
            if (hq <= 0) break;
        }
        if (live_enemies > 0 && hq > 0 && current_max_a > 0) {
            ll t = (hq + current_max_a - 1) / current_max_a;
            hq -= t * current_max_a;
        }

        int killed = n - live_enemies;
        cout << killed << '\n';
    }

    return 0;
}