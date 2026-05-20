#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int INF = 0x3f3f3f3f;
int k[N];
int d[N];
int n, a, b;

void bfs()
{
    memset(d, 0x3f, sizeof d);
    d[a] = 0;

    queue<int> q;
    q.push(a);
    while(q.size())
    {
        int x = q.front(); q.pop();
        if(x == b)
        {
            cout << d[b] << '\n';
            return ;
        }
        if(x + k[x] <= n)
        {
            int up = x + k[x];
            if(d[up] == INF)
            {
                d[up] = d[x] + 1;
                q.push(up);
            }
        }

        if(x - k[x] >= 1)
        {
            int down = x - k[x];
            if(d[down] == INF)
            {
                d[down] = d[x] + 1;
                q.push(down);
            }
        }
    }

    cout  << -1 << '\n';
}

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++) cin >> k[i];
    
    bfs();
    system("pause");
    return 0;
}