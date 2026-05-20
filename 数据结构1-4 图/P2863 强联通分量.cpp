#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
vector<int> g[N];

int dfn[N], low[N], tol;
int stk[N], top;
bool in[N];
int scc[N], siz[N], cnt;

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
        else if(in[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(dfn[x] == low[x])
    {
        int y; ++ cnt;
        do {
            y = stk[top --], in[y] = false;
            scc[y] = cnt;
            siz[cnt] ++;
        } while(y != x);
    }
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; i ++)
    {
        if(!dfn[i]) tarjan(i);
    }

    int ans = 0;
    for(int i = 1; i <= cnt; i ++) 
        if(siz[i
        ] > 1) ans ++;

    cout << ans << '\n';
    return 0;
}