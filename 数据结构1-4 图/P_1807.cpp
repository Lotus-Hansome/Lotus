#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e3 + 9;
const int INF = 1e9;

struct Node{
    int x;
    ll w;
};

vector<Node> g[N];
int in[N];
int n, m;
ll dp[N];

void topo()
{
    queue<int> q;
    for(int i = 1; i <= n; i ++) if(!in[i]) q.push(i);
    for(int i = 1; i <= n; i ++) dp[i] = -INF;

    while(q.size())
    {
        int x = q.front(); q.pop();
        if(x == 1) dp[1] = 0;
        for(const auto &t : g[x])
        {
            int y = t.x, w = t.w;
            dp[y] = max(dp[x] + w, dp[y]);
            if(-- in[y] == 0) q.push(y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});        
        in[v] ++;
    }

    topo();

    ll ans = 0;
    if(dp[n] == -INF) cout << -1 << '\n';
    else cout << dp[n] << '\n';
    return 0;
}