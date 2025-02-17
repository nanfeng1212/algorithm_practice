#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 35;

int n;
int dp[N][M];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        for(int j = 0; j < 31; j++)
        {
            if((x >> j) & 1) dp[i][j] = 1;
            dp[i][j] += dp[i - 1][j];
        }
    }
    
    int t;
    cin >> t;
    while(t--)
    {
        int ret = 0;
        int l, r;
        cin >> l >> r;
        for(int j = 0; j < 31; j++)
        {
            int one = dp[r][j] - dp[l - 1][j];
            int len = r - l + 1;
            if(one * 2 < len)
            {
                ret |= (1 << j);
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}