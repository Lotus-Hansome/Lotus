/*
本题是一个数学问题
对于一个n*n的表格，画一行能与表格有n个交点，画一列也能与表格产生n个交点
但是如果画一行和一列能得到2*n-1个交点，这是因为这两条直线有一个重复的点
同理，画两行两列有四个重复的格子
如果画n行m列呢？
对于每行，他们都是平行的，假设画n行，只需画一列就能产生n个交点
每多画一列就多n个交点，所以n行m列就有n*m个交点
因此对于一个n*n的表格，画a行b列能得到的格子数为n*(a+b) - a*b
所以我们只需统计有多少行和多少列会被攻击，就能得到被攻击的格子数量
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
unordered_map<int, bool> r, c;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }

    while('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }

    return x * f;
}

int main()
{
    int n, k;
    n = read();
    k = read();
    for(int i = 1; i <= k; i ++)
    {
        int a, b;
        a = read();
        b = read();
        r[a] = true;
        c[b] = true;
    }

    int cntr = r.size(), cntc = c.size();
    long long ans = 1LL * n * (cntr + cntc) - 1LL * cntr * cntc;
    cout << ans << '\n';
    return 0;
}