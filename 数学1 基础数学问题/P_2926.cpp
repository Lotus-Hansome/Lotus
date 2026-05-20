#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int a[N], cnt[N];
int ans[N];

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

inline void write(int x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    int n; n = read();
    for(int i = 1; i <= n; i ++)
    {
        a[i] = read();
        cnt[a[i]] ++;
    }
    for(int i = 1; i < N; i ++)
    {
        if(!cnt[i]) continue;
        for(int j = i; j < N; j += i) ans[j] += cnt[i];
    }

    for(int i = 1; i <= n; i ++)
    {
        write(ans[a[i]] - 1);
        putchar('\n');
    }

    return 0;
}