#include<bits/stdc++.h>
using namespace std;

const int N = 1009;

int a[N][N], d[N][N];

void insert(int x1, int y1, int x2, int y2)
{
    d[x1][y1] ++;
    d[x1][y2 + 1] --;
    d[x2 + 1][y1] --;
    d[x2 + 1][y2 + 1] ++;
}


int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        insert(x1, y1, x2, y2);
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            a[i][j] = d[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}