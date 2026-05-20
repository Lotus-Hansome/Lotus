#include<bits/stdc++.h>
using namespace std;

const int N = 150;
const int INF = 1e9 + 7;
int a[N][N];
int sum[N][N];

int getsum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    int ans = -INF;
    for(int U = 1; U <= n; U ++)
    {
        for(int D = U; D <= n; D ++)
        {
            int res = 0;
            vector<int> dp(N + 1, -INF); // 定义dp[i]表示前i个数中能得到的最大值
            
            int last = 0;
            for(int i = 1; i <= n; i ++)
            {
                int x = getsum(U, i, D, i);
                int cur = max(last + x, x);// cur其实也是dp，记录以i结尾的子序列的最小值
                dp[i] = max(dp[i - 1], cur);
                last = cur;
            }
            ans = max(ans, dp[n]);
        }
    }

    cout << ans << '\n';
    return 0;
}