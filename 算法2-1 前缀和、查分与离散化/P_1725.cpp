/*
不难发现这是一道DP题，用单调队列可以将时间复杂度优化为O(n)
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

const int INF = 1e9;

int a[N];
int dp[N];
int q[N], hh, tt;

int main()
{
    int n, l, r; cin >> n >> l >> r;
    for(int i = 0; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) dp[i] = -INF;

    hh = 1, tt = 0;
    for(int i = l; i <= n; i ++)
    {
        // for(int j = max(0, i - r); j <= i - l; j ++)
        // {
        //     dp[i] = max(dp[j] + a[i], dp[i]);
        // }
        while(hh <= tt && q[hh] < max(0, i - r)) hh ++;
        while(hh <= tt && dp[q[tt]] <= dp[i - l]) tt --;
        q[++ tt] = i - l;
        if(dp[q[hh]] != -INF) dp[i] = dp[q[hh]] + a[i];
    }

    int ans = -INF;
    // 注意下一步跳到的位置要大于n而不是大于等于n
    // 所以从n-r+1开始下一步才能跳出去
    for(int i = n - r + 1; i <= n; i ++) ans = max(ans, dp[i]);

    cout << ans << '\n';
    return 0;
}