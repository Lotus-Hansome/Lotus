// 求所有奶牛都能到达的牧场的数量
// 可以建反图，然后求能到达所有奶牛所在地点的牧场数量
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
vector<int> g[N];
int c[105];
bool vis[N];

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    while(q.size())
    {
        int x = q.front(); q.pop();
        if(vis[x]) continue;
        vis[x] = true;

        for(const auto &y : g[x])
        {
            if(!vis[y]) q.push(y);
        }
    }
}

int main()
{
    int k, n, m; cin >> k >> n >> m;
    for(int i = 1; i <= k; i ++) cin >> c[i];
    for(int i = 1; i <= m; i ++)
    {
        int u, v; cin >> u >> v;
        g[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        memset(vis, 0, sizeof(vis));
        bfs(i);
        bool flag = true;
        for(int j = 1; j <= k; j ++)
        {
            if(!vis[c[j]])
            {
                flag = false;
                break;
            }
        }

        if(flag) ans ++;
    }

    cout << ans << '\n';
    return 0;
}