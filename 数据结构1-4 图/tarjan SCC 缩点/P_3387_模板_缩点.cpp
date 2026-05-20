#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;

int a[N];
vector<int> g[N];
int dfn[N], low[N], tol;
int stk[N], top;
bool instk[N];
int scc[N], cnt;

vector<int> ne[N];
int nw[N], dp[N], in[N];

void tarjan(int x)
{
    dfn[x] = low[x] = ++ tol;
    stk[++ top] = x, instk[x] = true;
    for(const auto &y : g[x])
    {
        if(!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(dfn[x] == low[x])
    {
        int y; ++ cnt;
        do {
            y = stk[top --];
            instk[y] = false;
            scc[y] = cnt;
        } while(y != x);
    }
}

void rebuild(int n)
{
    for(int x = 1; x <= n; x ++)
    {
        nw[scc[x]] += a[x];
        for(const auto &y : g[x])
        {
            int a = scc[x], b = scc[y];
            if(a != b)
            {
                ne[a].push_back(b);
                in[b] ++;
            }
        }
    }
}

void topo()
{
    queue<int> q;
    for(int i = 1; i <= cnt; i ++) if(!in[i]) q.push(i);
    while(q.size())
    {
        int x = q.front(); q.pop();
        if(dp[x] == 0) dp[x] = nw[x];
        for(const auto &y : ne[x])
        {
            dp[y] = max(dp[x] + nw[y], dp[y]);
            if(-- in[y] == 0) q.push(y);
        }
    }   
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i ++)
        if(!dfn[i]) tarjan(i);

    rebuild(n);
    topo();
    int ans = 0;
    for(int i = 1; i <= n; i ++) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}