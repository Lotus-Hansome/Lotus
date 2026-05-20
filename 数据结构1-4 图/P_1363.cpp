/*
这道题的核心是判断在由 N×M 小迷宫无限平铺而成的无限大迷宫中，能否从起点走到距离起点无限远的地方。
关键观察：如果我们能在不同的小迷宫副本中到达同一个相对位置(取模后的位置)
那么就说明存在一条可以无限重复的路径，从而可以一直走下去，走到无限远处。
解题思路
我们使用深度优先搜索 (DFS) 来遍历迷宫，同时维护两个坐标系统：
相对坐标 (x, y)：通过取模运算映射到原始小迷宫的位置，范围始终在 [0, n-1] 和 [0, m-1] 之间
绝对坐标 (fx, fy)：记录实际的位置，不进行取模，可以是任意整数
判断条件：
当我们访问到一个已经被标记过的相对坐标 (x, y) 时
如果此时的绝对坐标 (fx, fy) 与之前记录的绝对坐标不同，说明我们在不同的小迷宫副本中到达了同一个位置，答案为 "Yes"
如果相同，说明只是在同一个小迷宫中绕圈，继续搜索
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1509;
int n, m;
char mp[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool vis[N][N];
int fx[N][N];
int fy[N][N];

bool dfs(int x, int y, int _x, int _y)
{
    if(vis[x][y])
    {
        if(fx[x][y] != _x || fy[x][y] != _y) return true;
        return false;
    }

    vis[x][y] = true;
    fx[x][y] = _x;
    fy[x][y] = _y;

    for(int i = 0; i < 4; i ++)
    {
        int nx = (x + dx[i] + n) % n, ny = (y + dy[i] + m) % m;
        int _nx = _x + dx[i], _ny = _y + dy[i];
        if(mp[nx][ny] == '#') continue;
        if(dfs(nx, ny, _nx, _ny)) return true;
    }

    return false;
}

void solve()
{
    memset(vis, 0, sizeof vis);
    memset(fx, 0, sizeof fx);
    memset(fy, 0, sizeof fy);
    int sx, sy;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            cin >> mp[i][j];
            if(mp[i][j] == 'S') sx = i, sy = j;
        }
    }
    if(dfs(sx, sy, sx, sy)) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    while(cin >> n >> m)
    {
        solve();
    }

    return 0;
}