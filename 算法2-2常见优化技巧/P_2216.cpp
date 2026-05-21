#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 9;

ll a[N][N];
ll col_mn[N][N], col_mx[N][N], row_mx[N][N], row_mn[N][N];
int q[N], hh, tt;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        hh = 1, tt = 0;
        for(int j = 1; j <= m; j ++)
        {
            while(hh <= tt && q[hh] < j - k + 1) hh ++;
            while(hh <= tt && a[i][q[tt]] < a[i][j]) tt --;
            q[++ tt] = j;
            col_mx[i][j] = a[i][q[hh]];
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        hh = 1, tt = 0;
        for(int j = 1; j <= m; j ++)
        {
            while(hh <= tt && q[hh] < j - k + 1) hh ++;
            while(hh <= tt && a[i][q[tt]] > a[i][j]) tt --;
            q[++ tt] = j;
            col_mn[i][j] = a[i][q[hh]];
        }
    }

    for(int j = k; j <= m; j ++)
    {
        hh = 1, tt = 0;
        for(int i = 1; i <= n; i ++)
        {
            while(hh <= tt && q[hh] < i - k + 1) hh ++;
            while(hh <= tt && col_mx[q[tt]][j] < col_mx[i][j]) tt --;
            q[++ tt] = i;
            row_mx[i][j] = col_mx[q[hh]][j];
        }
    }

    for(int j = k; j <= m; j ++)
    {
        hh = 1, tt = 0;
        for(int i = 1; i <= n; i ++)
        {
            while(hh <= tt && q[hh] < i - k + 1) hh ++;
            while(hh <= tt && col_mn[q[tt]][j] > col_mn[i][j]) tt --;
            q[++ tt] = i;
            row_mn[i][j] = col_mn[q[hh]][j];
        }
    }

    ll ans = 1e18;
    for(int i = k; i <= n; i ++)
    {
        for(int j = k; j <= m; j ++)
        {
            ll mi = row_mx[i][j] - row_mn[i][j];
            ans = min(ans, mi);
        }
    }

    cout << ans << '\n';
    return 0;
}