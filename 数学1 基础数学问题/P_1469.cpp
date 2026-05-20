#include<bits/stdc++.h>
using namespace std;

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
    int n; n = read();
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x = read();
        ans ^= x;
    }

    cout << ans << '\n';
    return 0;
}