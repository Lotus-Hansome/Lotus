#include<bits/stdc++.h>
using namespace std;

const int N = 405;
const int INF = 0x3f3f3f3f;

int t[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int d[N][N];

void bfs()
{
    memset(d, 0x3f, sizeof d);
    d[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    if(d[0][0] >= t[0][0])
    {
        cout << -1 << '\n';
        return ;
    }
    
    while(q.size())
    {
        int x = q.front().first, y = q.front().second; q.pop();
        if(t[x][y] == INF)
        {
            cout << d[x][y] << '\n';
            return ;
        }
        
        for(int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if(d[nx][ny] == INF && d[x][y] + 1 < t[nx][ny])
            {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << -1 << '\n';
}

int main()
{
    memset(t, 0x3f, sizeof t);
    int m; cin >> m;
    while(m --)
    {
        int x, y, time; cin >> x >> y >> time;
        t[x][y] = min(t[x][y], time);

        for(int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            // 注意这里要跟time取min而不是t[x][y]
            //因为t[x][y]的最小值可能是被烧焦的时间而不是被撞击的时间
            //而一个格子只有被撞击才会影响其相邻格子
            t[nx][ny] = min(t[nx][ny], time);
        }
    }

    bfs();

    return 0;
}