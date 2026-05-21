#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int a[N];
int q[N], hh, tt;

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
    int n, k; n = read(), k = read();
    for(int i = 1; i <= n; i ++) a[i] = read();

    hh = 1, tt = 0;
    for(int i = 1; i <= n; i ++)
    {
        while(hh <= tt && q[hh] < i - k + 1) hh ++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k) cout << a[q[hh]] << " ";
    }

    cout << '\n';

    hh = 1, tt = 0;
    for(int i = 1; i <= n; i ++)
    {
        while(hh <= tt && q[hh] < i - k + 1) hh ++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k) cout << a[q[hh]] << " ";
    }
    return 0;
}