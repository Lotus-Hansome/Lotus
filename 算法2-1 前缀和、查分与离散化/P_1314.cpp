/*
终于凭自己想出来了一道绿题....
需要将yi的公式化简
观察yi的公式可以知道只有wi>=W的vi才会对结果产生贡献
而每遇到一个wi>=W就对该区间中大于W的所有vi求一次和
因此所有的vi(对应的wi>=W)会被计算cnt次，cnt为区间中wi>=W的矿石数量
因此使用两个前缀和(求前缀和时间复杂度为O(n))可以将该公式计算优化为O(1)
又因为y是满足单调性的，所以结合二分求解即可
*/

#include<bits/stdc++.h>
using namespace std;

using i128 = __int128;
using ll = long long;

const int N = 2e5 + 9;

ll s;
int w[N], v[N];
int L[N], R[N];
int n, m;

void write(i128 x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

i128 calc(int W)
{
    vector<int> pre1(N, 0); // pre1[i]求出(1~i)有多少个大于等于W的数
    vector<ll> pre2(N, 0); // pre2[i]求出(1~i)中大于W的数之和
    for(int i = 1; i <= n; i ++)
    {
        pre1[i] = pre1[i - 1] + (w[i] >= W);
        pre2[i] = pre2[i - 1] + (w[i] >= W) * v[i]; 
    }

    i128 res = 0;
    for(int i = 1; i <= m; i ++)
    {
        int l = L[i], r = R[i];
        int cnt = pre1[r] - pre1[l - 1];
        ll sum = pre2[r] - pre2[l - 1];
        res += cnt * sum;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
    for(int i = 1; i <= m; i ++) cin >> L[i] >> R[i];

    int l = 0, r = 1e6 + 9, W;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(calc(mid) >= s) W = mid, l = mid + 1;
        else r = mid - 1;
    }

    i128 ans = calc(W) - s;
    ans = min(ans, s - calc(W + 1)); 
    write(ans);
    putchar('\n');
    return 0;
}