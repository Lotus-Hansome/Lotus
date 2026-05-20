#include<bits/stdc++.h>
using namespace std;

const int N = 105;

vector<int> g[N];
int dep[N], cnt[N], fa[N][15];

void dfs(int x, int p)
{
    dep[x] = dep[p] + 1;
    fa[x][0] = p;
    cnt[dep[x]] ++;
    for(int i = 1; i <= 10; i ++) fa[x][i] = fa[fa[x][i - 1]][i - 1];

    for(const auto &y : g[x]) dfs(y, x);
}

int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);

    for(int i = 10; i >= 0; i --)
    {
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    }

    if(x == y) return x;

    for(int i = 10; i >= 0; i --)
    {
        if(fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i < n; i ++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    dfs(1, 0);

    int x, y; cin >> x >> y;

    int mx_dep = 0, mx_wid = 0;
    for(int i = 1; i <= n; i ++)
    {
        mx_dep = max(mx_dep, dep[i]);
        mx_wid = max(mx_wid, cnt[dep[i]]);
    }

    cout << mx_dep << '\n';
    cout << mx_wid << '\n';
    
    int ansc = lca(x, y);

    // 节点 u,v 之间的距离表示从 u 到 v 的最短有向路径上向根节点的边数的两倍加上向叶节点的边数。
    // 向根节点的边数就是u到LCA(u, v)的路径上的边数，向叶节点的边数就是LCA(u, v)到v的边数
    cout << 2 * (dep[x] - dep[ansc]) + dep[y] - dep[ansc] << '\n';

    system("pause");
    return 0;
}