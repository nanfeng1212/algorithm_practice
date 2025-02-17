#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> costs;  // 存储代价
    double pi = 3.14159265358979324;

    for (int i = 0; i < n; ++i) {
        double x, y, r;
        cin >> x >> y >> r;
        double distanceToOrigin = sqrt(x*x+y*y);
        // 判断该圆是否包含原点
        if(distanceToOrigin<r){
            // 计算将该圆移动到包含原点的代价
            double moveDistance = r-distanceToOrigin;
            double area = pi * r * r;
            double cost = moveDistance * area;
            costs.push_back(cost);  // 记录代价
        }
    }

    // 如果不需要移动（即不包含原点的圆不超过 k 个）
    if (costs.size() <= k) {
        cout << fixed << setprecision(6) << 0.0 << endl;
        return 0;
    }
    // 排序并选择代价最小的 n - k 个
    sort(costs.begin(), costs.end());

    double result = 0.0;
    for (int i = 0; i < costs.size() - k; ++i) {
        result += costs[i];
    }

    cout << fixed << setprecision(6) << result << endl;
    return 0;
}
