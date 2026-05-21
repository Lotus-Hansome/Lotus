#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int a[N];
int dp[N]; // 定义dp[i]为以i结尾的子序列中和最大的子序列的和

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    int ans = INT_MIN;
    for(int i = 1; i <= n; i ++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
    return 0;
}