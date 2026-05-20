#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;

vector<int> g[N];
int in[N], w[N];// in[i]为点的入度, w[i]为点权
int dp[N];
int n;

void topo()
{
    queue<int> q;
    for(int i = 1; i <= n; i ++)
    {
        if(!in[i])
        {
            q.push(i);
            dp[i] = w[i];
        }
    }

    while(q.size())
    {
        int x = q.front(); q.pop();
        for(const auto &y : g[x])
        {
            dp[y] = max(dp[x] + w[y], dp[y]);
            if(-- in[y] == 0) q.push(y);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int id; cin >> id;
        cin >> w[id];
        int x; cin >> x;
        while(x != 0)
        {
            g[x].push_back(id);
            in[id] ++;
            cin >> x;
        }
    }

    topo();

    int ans = 0;
    for(int i = 1; i <= n; i ++) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}