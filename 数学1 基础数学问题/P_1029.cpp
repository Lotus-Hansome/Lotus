#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int Gcd(int m, int n)
{
    return n == 0 ? m : Gcd(n, m % n);
}

int lcm(int m, int n)
{
    return 1ll * m * n / Gcd(m, n);
}

int main()
{
    int a, b; cin >> a >> b;
    ll x = 1ll * a * b;
    
    int ans = 0;
    for(int i = 1; i <= x / i; i ++)
    {
        if(Gcd(i, x / i) != a || lcm(i, x / i) != b) continue;
        if(x % i == 0) ans ++;
        if(i != x / i) ans ++;
    }

    cout << ans << '\n';
    return 0;
}