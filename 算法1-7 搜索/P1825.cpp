#include<bits/stdc++.h>
using namespace std;

const int N = 305;
const int INF = 0x3f3f3f3f;

char mp[N][N];
int n, m; 
int sx, sy, fx, fy;
pair<int, int> to[N][N];
int d[N][N][2];

struct Node{
    int x, y, t;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inmp(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs()
{
    deque<Node> q;
    memset(d, 0x3f, sizeof d);
    d[sx][sy][0] = 0;
    q.push_back({sx, sy, 0});

    while(q.size())
    {
        int x = q.front().x, y = q.front().y, t = q.front().t;q.pop_front();

        if(x == fx && y == fy)
        {
            cout << d[fx][fy][t] << '\n';
            return ;
        }
    
        if(isupper(mp[x][y]) && t == 0)
        {
            int nx = to[x][y].first, ny = to[x][y].second;
            if(d[x][y][t] < d[nx][ny][1])
            {
                d[nx][ny][1] = d[x][y][0];
                q.push_front({nx, ny, 1});
            }
        }else{
            for(int i = 0; i < 4; i ++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(!inmp(nx, ny) || mp[nx][ny] == '#') continue;

                if(d[x][y][t] + 1 < d[nx][ny][0])
                {
                    d[nx][ny][0] = d[x][y][t] + 1;
                    q.push_back({nx, ny, 0});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> mp[i][j];
    
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(mp[i][j] == '@') sx = i, sy = j;
            if(mp[i][j] == '=') fx = i, fy = j;
            if(isupper(mp[i][j]))
            {
                for(int _i = 1; _i <= n; _i ++)
                {
                    for(int _j = 1; _j <= m; _j ++)
                    {
                        if(_i == i && _j == j) continue;
                        if(mp[_i][_j] == mp[i][j]) to[i][j] = make_pair(_i, _j);
                    }
                }
            }
        }
    }

    bfs();
    system("pause");

    return 0;
}