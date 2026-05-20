/*
本题考察筛法
注意到R的范围很大，如果直接用筛法去筛出1~R中的素数，时间复杂度为O(n)，肯定会超时
而我们只需要求这个区间中的素数个数，区间大小只有1e6
所以可以去筛出这个范围的合数，剩下的就是素数了
对于一个合数n，可以表示为他的最小质因子a*他的最大因子b
而他的最小质因子a一定不超过sqrt(n)
假设他的最小质因子超过sqrt(n)，那么b一定小于sqrt(n)
那么b一定有一个最小质因子小于sqrt(n)，即a不是n的最小质因子
所以我们只需要把sqrt(R)范围内的最小质因子筛出来，然后再用最小质因子去筛[L, R]范围内的合数即可
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 9;

int primes[N], cnt;
bool vis[N];

void euler(int n)
{
    vis[0] = vis[1] = true;
    for(int i = 2; i <= n; i ++)
    {
        if(!vis[i]) primes[++ cnt] = i;
        for(int j = 1; j <= cnt && 1ll * i * primes[j] <= n; j ++)
        {
            vis[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int L, R; cin >> L >> R;
    int n = sqrt(R);
    euler(n);
    memset(vis, 0, sizeof vis);

    for(int i = 1; i <= cnt; i ++)
    {
        ll p = primes[i];
        // 对于最小质因子为p的合数，如果L不包含p，我们可以直接从大于L的第一个p的倍数开始筛
        ll s = (L + p - 1) / p * p;
        // 如果p包含在这个区间中，我们得从2p开始，因为p是一个质数
        if(s < 2 * p) s = 2 * p;
        for(ll j = s; j <= R; j += p)
        {
            // 注意这里将[L, R]范围内的合数转换成映射，否则会超出内存
            vis[j - L + 1] = true;
        }
    }

    int ans = 0;
    for(int i = 1; i <= R - L + 1; i ++) if(!vis[i]) ans ++;
    // 如果L是从1开始的，由于1不是素数，而1并不会被筛掉，所以需要特判一下
    if(L == 1) ans --; 
    cout << ans << '\n';
    return 0;
}