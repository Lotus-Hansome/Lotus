#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll x, y; cin >> x >> y;
    if(x > y) swap(x, y);
    ll ans = 0;
    while(true)
    {
        ll cnt = y / x;
        ans += cnt * 4 * x;
        y %= x;
        if(y == 0) break;
        swap(x, y);
    }

    cout << ans << '\n';
    return 0;
}