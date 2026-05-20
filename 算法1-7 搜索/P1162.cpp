#include<bits/stdc++.h>
using namespace std;

const int N = 35;
char mp[N][N];
int n;
bool vis[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inmp(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i ++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(!inmp(nx, ny) || vis[nx][ny] || mp[nx][ny] == '1') continue;
        dfs(nx, ny);
    }
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> mp[i][j];

    for(int i = 1; i <= n; i ++)
    {
        if(mp[1][i] == '0' && !vis[1][i]) dfs(1, i);
        if(mp[n][i] == '0' && !vis[n][i]) dfs(n, i);
        if(mp[i][1] == '0' && !vis[i][1]) dfs(i, 1);
        if(mp[i][n] == '0' && !vis[i][n]) dfs(i, n);
    }
    
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(!vis[i][j] && mp[i][j] == '0') cout << '2' << ' ';
            else cout << mp[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}