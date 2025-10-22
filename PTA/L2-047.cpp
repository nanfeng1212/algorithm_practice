#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 19;
struct node {
    int win;
    int lose;
} tree[N];
int k;
bool dfs(int n) {
    if (n >= 1<<k)
        return true;
    else if (tree[n].lose>tree[n].win)
        return false;
    tree[n<<1].win = tree[n].win;
    tree[n<<1|1].win = tree[n].lose;
    if (dfs(n<<1) && dfs(n<<1|1))
        return true;
    swap(tree[n<<1].win, tree[n<<1|1].win);
    if (dfs(n<<1) && dfs(n<<1|1))
        return true;
    return false;
}
int main() {
    cin >> k;
    for (int i=k; i>=1; i--)
        for (int j = 1<<(i-1); j < 1<<i; j++)
            cin >> tree[j].lose;
    cin >> tree[1].win;
    if (dfs(1))
        for (int j = 1<<k-1; j < 1<<k; j++)
            cout << tree[j].win << ' ' << tree[j].lose << " \n"[j == (1 << k) - 1];
    else
        cout << "No Solution" << endl;
    return 0;
}
