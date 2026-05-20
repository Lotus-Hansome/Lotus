/*
这题的范围不能用线性筛去求欧拉函数phi(x)，只能使用试除法
求小于等于x的数中与x不互质的数的个数
也就是求x-phi(x)
根据欧拉函数的公式，即可求出phi(x)
即将x的每个质因子pi都除以一遍然后再乘以pi-1
质因子只需枚举到sqrt(x)即可，先让phi[x]=x,val[x]=x
然后每遇到一个质因子pi就让phi[x]/pi*(pi-1),同时让val[x]把这个质因子除干净
如果sqrt(x)内的质因子枚举完了val[x]还大于1，此时val[x]就是大于sqrt(x)的那个质因子
对于任何数来说，大于sqrt(x)的质因子最多只有1个，所以再把phi[x]/val[x]*(val[x] - 1)即可
这也就是唯一分解定理的原理和求phi(x)的原理
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 9;
const ll MOD = 666623333;

bool vis[N];
ll phi[N], val[N];
int primes[N], cntp;

void euler(ll n)
{
    vis[0] = vis[1] = true;
    for(int i = 2; i <= n; i ++)
    {
        if(!vis[i]) primes[++ cntp] = i;

        for(int j = 1; j <= cntp && 1ll * i * primes[j] <= n; j ++)
        {
            vis[i * primes[j]] =  true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    ll l, r; cin >> l >> r;
    euler(sqrtl(r));

    for(ll i = l; i <= r; i ++)
    {
        val[i - l + 1] = phi[i - l + 1] = i;
    }

    for(int i = 1; i <= cntp; i ++)
    {
        ll p = primes[i];
        ll s = (p + l - 1) / p * p;
        if(s < 2 * p) s = 2 * p;
        for(ll j = s; j <= r; j += p)
        {
            phi[j - l + 1] = phi[j - l + 1] / p * (p - 1);
            while(val[j - l + 1] % p == 0) val[j - l + 1] /= p; // 将该质因数除干净
        }
    }

    ll ans = 0;
    for(int i = 1; i <= r - l + 1; i ++)
    {
        // 如果val[i]没除完，说明剩下的val[i]是大于sqrt(i+l-1)的质因子
        // 由于x中大于sqrt(x)的质因子只可能有一个，所以继续更新phi[i]
        if(val[i] > 1) phi[i] = phi[i] / val[i] * (val[i] - 1);
        ans = (ans + (i + l - 1 - phi[i]) % MOD) % MOD;
    }

    cout << ans << '\n';
    return 0;
}