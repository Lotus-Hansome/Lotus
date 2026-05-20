#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 9;
const int MOD = 80112002;

int n, m;
vector<int> g[N];
int in[N], out[N];
int dp[N];

void topo()
{
    queue<int> q;
    for(int i = 1; i <= n; i ++)
    {
        if(!in[i])
        {
            q.push(i);
            dp[i] = 1;
        }
    }

    while(q.size())
    {
        int x = q.front(); q.pop();
        for(const auto &y : g[x])
        {
            dp[y] = (dp[x] + dp[y]) % MOD;
            if(-- in[y] == 0) q.push(y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        out[a] ++;
        in[b] ++;
    }

    topo();

    int ans = 0;
    for(int i = 1; i <= n; i ++)
        if(!out[i]) ans = (ans + dp[i]) % MOD;

    cout << ans << '\n';
    return 0;
}