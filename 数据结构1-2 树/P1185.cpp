#include<bits/stdc++.h>
using namespace std;

const int N = 4e3 + 9;
char a[N][N];
struct Node{
    int x, y;
}node[15][530];

int m, n;

void del(int x, int y)
{
    if(a[x][y] == ' ') return ;
    a[x][y] = ' ';

    if(a[x - 1][y + 1] == '/') del(x - 1, y + 1);
    if(a[x - 1][y - 1] == '\\') del(x - 1, y - 1);

    del(x + 1, y - 1);
    del(x + 1, y + 1);
}

void solve()
{
    int _x, _y; cin >> _x >> _y;
    int x = node[_x][_y].x, y = node[_x][_y].y;
    del(x, y);
}

int main()
{
    cin >> m >> n;
    
    memset(a, ' ', sizeof a);

    int _m = 3 * (1 << m - 2), row = m;

    for(int j = 1; j <= 2 * _m; j += 6) a[_m][j] = a[_m][j + 4] = 'o';

    for(int i = _m; i >= 2; i --)
    {
        int f = 1, col = 0;
        bool flag = false;
        for(int j = 1; j <= 2 * _m; j ++)
        {
            if(a[i][j] == '/')
            {
                if(a[i][j + 2] == '\\')
                {
                    if(i == 2)
                    {
                        node[1][1].x = i - 1;
                        node[1][1].y = j + 1;
                    }
                    a[i - 1][j + 1] = 'o';
                    j += 2;
                }
                else a[i - 1][j + 1] = '/';
            }
            else if(a[i][j] == '\\') a[i - 1][j - 1] = '\\';
            else if(a[i][j] == 'o')
            {
                flag = true;
                col ++;
                node[row][col].x = i, node[row][col].y = j;
                if(f) a[i - 1][j + 1] = '/';
                else a[i - 1][j - 1] = '\\';
                f ^= 1;
            }
        }
        if(flag) row --;
    }

    while(n --) solve();
    
    for(int i = 1; i <= _m; i ++)
    {
        for(int j = 1; j <= 2 * _m; j ++) 
            putchar(a[i][j]);
        putchar('\n');
    }

    system("pause");
    return 0;
}