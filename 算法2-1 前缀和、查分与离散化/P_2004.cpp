#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 9;

int a[N][N];
ll sum[N][N];

ll getsum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

int main()
{
    int n, m, c; cin >> n >> m >> c;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    ll ans = -1e18;
    ll x, y;
    for(int i = 1; i <= n - c + 1; i ++)
    {
        for(int j = 1; j <= m - c + 1; j ++)
        {
            ll s = getsum(i, j, i + c - 1, j + c - 1);
            if(s > ans)
            {
                ans = s;
                x = i, y = j;
            }
        }
    }

    cout << x << " " << y << '\n';
    return 0;
}