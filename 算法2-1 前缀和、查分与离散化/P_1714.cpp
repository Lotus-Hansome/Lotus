/*
求∑(i=l~r)pi(r-m+1<=l<=r)的最大值
也就是求pre[r+1]-pre[l](r-m+1<=l<=r)的最大值
我们可以对于每个pre[r+1]，去求满足条件的最小的pre[l]，也就是求长度为m的滑动窗口的最小值
可以用单调队列求解
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

int pre[N];

int q[N], hh, tt;

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        int p; cin >> p;
        pre[i] = pre[i - 1] + p;
    }

    hh = 1, tt = 0;
    int ans = INT_MIN;
    for(int i = 0; i < n; i ++)
    {
        while(hh <= tt && q[hh] < i - m + 1) hh ++;
        while(hh <= tt && pre[q[tt]] >= pre[i]) tt --;
        q[++ tt] = i;
        ans = max(ans, pre[i + 1] - pre[q[hh]]);
    }

    cout << ans << '\n';
    return 0;
}