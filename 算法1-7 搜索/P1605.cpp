#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int fx, fy;
int n, m, t;

bool p[N][N];
bool vis[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inmp(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int dfs(int x, int y)
{
    if(x == fx && y == fy) return 1;

    int res = 0;
    for(int i = 0; i < 4; i ++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(vis[nx][ny] || !inmp(nx, ny) || p[nx][ny]) continue;

        vis[nx][ny] = true;
        res += dfs(nx, ny);
        vis[nx][ny] = false;
    }

    return res;
}

int main()
{
    cin >> n >> m >> t;
    int sx, sy;
    cin >> sx >> sy >> fx >> fy;

    while(t --)
    {
        int x, y; cin >> x >> y;
        p[x][y] = true;
    }

    vis[sx][sy] = true;
    cout << dfs(sx, sy) << '\n';
    return 0;
}