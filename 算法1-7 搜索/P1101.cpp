#include<bits/stdc++.h>
using namespace std;

const int N = 105;

string s = "yizhong";
char mp[N][N];
char ans[N][N];
int n;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool inmp(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool dfs(int x, int y, int idx, int i)
{
    if(idx == 6) return true;

    int nx = x + dx[i], ny = y + dy[i];
    if(!inmp(nx, ny) || mp[nx][ny] != s[idx + 1]) return false;

    return dfs(nx, ny, idx + 1, i);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            cin >> mp[i][j];
        }
    }

    memset(ans, '*', sizeof ans);
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(mp[i][j] == 'y')
            {
                for(int _i = 0; _i < 8; _i ++)
                {
                    if(dfs(i, j, 0, _i))
                    {
                        int x = i, y = j;
                        for(int _j = 0; _j <= 6; _j ++)
                        {
                            ans[x][y] = s[_j];
                            x += dx[_i], y += dy[_i];
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            cout << ans[i][j];
        }
        cout << '\n';
    }

    system("pause");

    return 0;
}