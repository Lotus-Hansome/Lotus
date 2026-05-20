/*
本题考察质因数分解(唯一分解定理)
对于细胞i，每次分裂后细胞数量都乘Si
对于M=m1的m2次方，怎么判断细胞分裂后是否能整除M或者整除M所需最少分裂次数呢
可以将m1质因数分解，只要Si包含m1的所有质因数，那么他分裂一定次数后就一定能整除m1
对于他需要分裂多少次，我们只需要对每个质因子都去求一下然后取最大值即可
假设m1的第一个质因子为x，m1的m2次方所拥有的x的数量为m1所拥有的x的数量cnt2乘以m2
设Si拥有x的数量为cnt1，每次分裂后拥有x的数量都增加cnt1(注意不是乘2)
最少分裂次数即cnt2*m2/cnt1，对每个质因子都求一遍最少次数然后去最大值就可以得到该细胞分裂所需的最少时间
然后对所有细胞需要的时间去最小值
注意需要判断该细胞分裂一定次数后能否为M的倍数，如果不满足条件就不需要统计
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e4 + 9;
const int INF = INT_MAX;

pair<int, int> fac[N];
int cntp;

void fen(int x)
{
    for(int i = 2; i <= x / i; i ++)
    {
        if(x % i) continue;
        int cnt = 0;
        while(x % i == 0)
        {
            x /= i;
            cnt ++;
        }
        fac[++ cntp] = make_pair(i, cnt);
    }

    if(x > 1) fac[++ cntp] = make_pair(x, 1);
}

int main()
{
    int n; cin >> n;
    int m1, m2; cin >> m1 >> m2;
    fen(m1);

    int ans = INF;
    for(int i = 1; i <= n; i ++)
    {
        int s; cin >> s;
        bool flag = true;
        int res = 0;
        for(int j = 1; j <= cntp; j ++)
        {
            int cnt1 = 0;
            int x = fac[j].first, cnt2 = fac[j].second;

            if(s % x != 0)
            {
                flag = false;
                break;
            }else {
                while(s % x == 0)
                {
                    s /= x;
                    cnt1 ++;
                }
                int cnt = ceil(1.0 * cnt2 * m2 / cnt1);
                res = max(res, cnt);
            }
        }

        if(flag) ans = min(ans, res);
    }
    
    
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}