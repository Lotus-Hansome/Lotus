/*
由于x和a0的最大公约数是a1，x和b0的最小公倍数为b1
所以x是b1的因子，是a1的倍数
因此直接枚举就行
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int Gcd(int m, int n)
{
    return n == 0 ? m : Gcd(n, m % n);
}

int lcm(int m, int n)
{
    return m / Gcd(m, n) * n;
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int a0, a1, b0, b1; cin >> a0 >> a1 >> b0 >> b1;
        int ans = 0;
        for(int j = 1; j <= b1 / j; j ++)
        {
            if(b1 % j) continue;
            int x = b1 / j;
            if(j % a1 == 0)
            {
                if(Gcd(j, a0) == a1 && lcm(j, b0) == b1) ans ++;
            }
            if(x == j) continue;
            if(x % a1 == 0)
            {
                if(Gcd(x, a0) == a1 && lcm(x, b0) == b1) ans ++;
            }
            
        }

        cout << ans << '\n';
    }

    return 0;
}