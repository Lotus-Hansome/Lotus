#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];

bool vis[N];

void dfs(int x)
{
    vis[x] = true;
    cout << x << " ";
    for(const auto &y : g[x])
    {
        if(vis[y]) continue;
        dfs(y);
    }
}

void bfs(int st)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(st);
    while(q.size())
    {
        int x = q.front(); q.pop();
        if(vis[x]) continue;
        cout << x << " ";
        vis[x] = true;
        for(const auto &y : g[x])
        {
            if(!vis[y]) q.push(y);
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }
    for(int i = 1; i <= n; i ++) sort(g[i].begin(), g[i].end());

    dfs(1);
    cout << '\n';
    bfs(1);

    return 0;
}