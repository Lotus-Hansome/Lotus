#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 9;
ll a[N], b[N];
ll n, m;

bool check(ll x)
{
    ll res = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(a[i] >= x) res += (a[i] - x - 1) / b[i] + 1;
    }
    return res <= m;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];

    ll l = 0, r = 1e12, ans;
    while(l <= r)
    {
        ll mid = l + r >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}