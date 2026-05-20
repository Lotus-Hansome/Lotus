#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 9;

int C[N][N];
int pre[N][N];
int k;

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

void write(int x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void init()
{
    C[0][0] = 1;
    for(int i = 1; i <= 2000; i ++)
    {
        C[i][0] = 1;
        for(int j = 1; j <= i; j ++)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
            pre[i][j] = pre[i - 1][j] + (C[i][j] == 0);
        }
    }
}

void solve()
{
    int n, m; 
    n = read(); 
    m = read();
    
    int ans = 0;
    for(int i = 0; i <= n; i ++)
    {
        if(i <= m) ans += pre[i][i];
        else ans += pre[i][m];
    }
    write(ans);
    putchar('\n');
}

int main()
{
    int t; 
    t = read();
    k = read();

    init();
    while(t --)
    {
        solve();
    }

    return 0;
}