/*
这题可以用排列组合技巧优化(题解)
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 55;

struct Num{
    int a[55];
    int len;
    Num() {
        memset(a, 0, sizeof a);
        len = 0;
    }

    Num operator + (const Num x)const{
        Num res;
        res.len = max(len, x.len);
        for(int i = 1; i <= max(len, x.len); i ++)
        {
            res.a[i] += x.a[i] + a[i];
            if(res.a[i] >= 10)
            {
                res.a[i + 1] += res.a[i] / 10;
                res.a[i] %= 10;
                res.len = max(res.len, i + 1);
            }
        }
        return res;
    }
}dp[N][N][N];

int main()
{
    int n, a, b; cin >> n >> a >> b;
    dp[0][0][0].len = 1, dp[0][0][0].a[1] = 1;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 0; j <= a; j ++)
        {
            for(int k = 0; k <= b; k ++)
            {
                for(int l = 0; l <= j; l ++)
                {
                    for(int t = 0; t <= k; t ++)
                    {
                        dp[i][j][k] = dp[i][j][k] + dp[i - 1][j - l][k - t];
                    }
                }
            }
        }
    }

    Num ans;
    ans.len = 0;
    for(int j = 0; j <= a; j ++)
    {
        for(int k = 0; k <= b; k ++)
        {
            ans = ans + dp[n][j][k];
        }
    }

    for(int i = ans.len; i >= 1; i --) cout << ans.a[i];
    return 0;
}