/*
本题考察枚举+差分+贪心
向将F转成1，B转成0，方便后续运算
每次操作可以将k头连续的牛的转向
当k固定时，怎么求出最小操作次数呢？
对于每头牛来说，翻转偶数次都等于没翻转
贪心策略为：
对于从左到右出现的每一次B，以他为起点的区间只需要翻转一次即可得到最少操作次数
可以从左往右扫描，假设当前牛(编号为i)0，那么就要将[i,i+len-1]区间内的牛转向
如果采用暴力枚举，对于每个长度，求最少操作次数的时间复杂度为O(n^2)
总时间复杂度为O(n^3)
由于第三层循环是对区间进行修改，所以可以用差分来代替
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 9;
bool a[N];
int d[N];

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        char ch; cin >> ch;
        a[i] = (ch == 'F' ? 1 : 0);
    }
    
    int m = INT_MAX, k = INT_MAX;
    for(int len = 1; len <= n; len ++)
    {
        int cnt = 0;
        memset(d, 0, sizeof d);

        bool flag = true;
        int sum = 0;
        for(int i = 1; i <= n; i ++)
        {
            sum += d[i]; // 第i头牛的翻转次数
            if(a[i] ^ (sum & 1) == 0)
            {
                cnt ++;
                if(i + len - 1 > n) // 无解
                {
                    flag = false;
                    break;
                }
                // d[i] ++;
                sum ++; // 由于d[i]++，所以sum也需要++
                d[i + len] --;
            }
        }

        if(cnt < m && flag)
        {
            m = cnt;
            k = len;
        }
    }

    cout << k << " " << m;
    return 0;
}