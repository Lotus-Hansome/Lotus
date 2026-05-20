#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll Gcd(ll m, ll n)
{
    return n == 0 ? m : Gcd(n, m % n);
}

ll Lcm(ll m, ll n)
{
    return m * n / Gcd(m, n);
}

int main()
{
    ll a, b, c; cin >> a >> b >> c;
    ll ans = Lcm(Lcm(a, b), c);
    cout << ans << '\n';
    return 0;
}