#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

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

void solve()
{
    mp.clear();
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int x; x = read();
        if(mp.count(x)) continue;

        cout << x << ' ';
        mp[x] ++;
    }

    cout << '\n';
}

int main()
{
    int t; t = read();
    while(t --)
    {
        solve();
    }

    return 0;
}