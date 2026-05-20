/*
本题考察差分
相邻城市间即为一个左闭右开的区间
*/


#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 9;

int p[N];
int a[N], b[N], c[N];
int diff[N];

int main()
{
    int n, m; cin >> n >> m;

    for(int i = 1; i <= m; i ++) cin >> p[i];
    for(int i = 1; i <= n - 1; i ++) cin >> a[i] >> b[i] >> c[i];

    for(int i = 1; i <= m - 1; i ++)
    {
        int l = min(p[i], p[i + 1]);
        int r = max(p[i], p[i + 1]);
        diff[l] ++;
        diff[r] --;
    }

    ll sum = 0, ans = 0;
    for(int i = 1; i <= n - 1; i ++)
    {
        sum += diff[i];
        ll cost = min(1ll * a[i] * sum, 1ll * b[i] * sum + c[i]);
        ans += cost;
    }

    cout << ans << '\n';
    return 0;
}