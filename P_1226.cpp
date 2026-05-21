#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll qmi(ll m, ll n, ll p)
{
    ll res = 1;
    while(n)
    {
        if(n & 1) res = res * m % p;
        m = m * m % p;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll a, b, p; cin >> a >> b >> p;
    cout << a <<  "^" << b << " mod " << p << "=" << qmi(a, b, p) << '\n';
    return 0;
}