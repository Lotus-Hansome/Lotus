/*
本题可以使用约数和定理求解
即sum = ∏(i=1~m)∑(j=0~ki)pi^j,m为约数个数,ki为x中质因子pi的个数
在求和时可以等比数列优化掉一层循环,内层就变为了(pi^(ki+1) - 1)/(pi-1)
但由于有分母,所以需要求逆元
当pi-1与MOD互质时，可以用费马小定理求逆元
当pi-1与MOD不互质时，因为MOD是一个质数，所以pi-1肯定大于MOD
所以(pi-1)%MOD=0，也就是pi=1(mod9901)
所以此时内层求和项就变成了1%MOD+(pi%MOD)+(pi^2%MOD)+...+(pi^ki%MOD)=1+1+...+1
也就是ki+1
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 9901;

vector<pair<ll, ll>> fac;

void fen(ll n, ll m)
{
    for(ll i = 2; i <= n / i; i ++)
    {
        if(n % i) continue;
        ll cnt = 0;
        while(n % i == 0)
        {
            cnt ++;
            n /= i;
        }
        fac.emplace_back(i, cnt * m);
    }

    if(n > 1) fac.emplace_back(n, m);
}

ll qmi(ll m, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1) res = res * m % MOD;
        m = m * m % MOD;
        n >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return qmi(x, MOD - 2);
}

ll Gcd(ll m, ll n)
{
    return n == 0 ? m : Gcd(n, m % n);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    fen(a, b);

    ll ans = 1;
    for(const auto &u : fac)
    {
        ll p = u.first, cnt = u.second;
        ll res = 0;
        if(Gcd(p - 1, MOD) == 1) res = (qmi(p, cnt + 1) - 1 + MOD) % MOD * inv(p - 1) % MOD;
        else res = (1 + cnt) % MOD;
        
        ans = ans * res % MOD;
    }

    cout << ans << '\n';
    return 0;
}