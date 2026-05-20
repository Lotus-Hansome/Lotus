#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

vector<int> g[N];

int dfn[N], low[N], tol;
int stk[N], top;
bool in[N];
int scc[N], cnt, mx_id[N];

int dp[N];
vector<int> ne[N];
bool vis[N];

void tarjan(int x)
{
    dfn[x] = low[x] = ++ tol;
    stk[++ top] = x, in[x] = true;

    for(const auto &y : g[x])
    {
        if(!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(in[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(low[x] == dfn[x])
    {
        int y; cnt ++;
        do {
            y = stk[top --]; in[y] = false;
            scc[y] = cnt;
        } while(y != x);
    }
}

void dfs(int x)
{
    vis[x] = true;
    dp[x] = mx_id[x];
    for(const auto & y : ne[x])
    {
        if(!vis[y]) dfs(y);
        dp[x] = max(dp[x], dp[y]);
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

    for(int i = 1; i <= n; i ++)
        if(!dfn[i]) tarjan(i);

    for(int x = 1; x <= n; x ++)
    {
        mx_id[scc[x]] = max(mx_id[scc[x]], x);
        for(const auto &y : g[x])
        {
            int a = scc[x], b = scc[y]; 
            if(a != b)
            {
                ne[a].push_back(b);
            }
        }
    }

    for(int i = 1; i <= cnt; i ++)
    {
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i ++) cout << dp[scc[i]] << " ";

    return 0;
}