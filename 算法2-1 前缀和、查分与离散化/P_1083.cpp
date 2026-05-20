/*
本题考察二分+差分
如果可以满足前x个订单的要求，那么前i(i<=x)个订单的要求也一定可以满足
要查找出第一个不满足要求的订单编号i
也就是要查找出i，使得前i个订单恰好不满足要求，而前i-1个订单可以满足要求
所以可以二分查找出这个最小的i
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 9;

int a[N], cnt[N], L[N], R[N];
ll diff[N]; // 不要忘记开longlong
int n, m;

bool Check(int x)
{
    memset(diff, 0, sizeof diff);

    for(int i = 1; i <= x; i ++)
    {
        diff[L[i]] += cnt[i];
        diff[R[i] + 1] -= cnt[i];
    }

    ll sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        sum += diff[i];
        if(sum > a[i]) return true; // 不能满足前x个订单的要求
    }
    
    // 能满足前x个订单的要求
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> cnt[i] >> L[i] >> R[i];
    int l = 1, r = m, ans = 0;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(Check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    if(!ans) cout << 0 << '\n';
    else {
        cout << -1 << '\n';
        cout << ans << '\n';
    }
    return 0;
}