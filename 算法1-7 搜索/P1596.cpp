#include<bits/stdc++.h>
using namespace std;

const int N = 105;

char mp[N][N];
int tol;
int n, m;
int col[N][N];

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

bool inmp(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void dfs(int x, int y)
{
    col[x][y] = tol;
    
    for(int i = 0; i < 8; i ++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(!inmp(nx, ny)) continue;
        if(col[nx][ny] || mp[nx][ny] == '.') continue;

        dfs(nx, ny);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> mp[i][j];
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(mp[i][j] == 'W' && !col[i][j])
            {
                tol ++;
                dfs(i, j);
            }
        }
    }

    cout << tol << '\n';

    system("pause");
    return 0;
}