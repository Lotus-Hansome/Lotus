#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
bool g[N][N];
int ind[N];
int a[N];
bool vis[N];

void topo(int n)
{
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i ++) if(!ind[i]) q.push(make_pair(i, 1));
    int ans = 0;
    while(q.size())
    {
        int x = q.front().first, dep = q.front().second;
        q.pop();
        ans = max(ans, dep);
        for(int y = 1; y <= n; y ++)
        {
            if(!g[x][y]) continue;
            if(-- ind[y] == 0) q.push(make_pair(y, dep + 1));
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int s; cin >> s;
        
        memset(vis, 0, sizeof vis);
        for(int j = 1; j <= s; j ++)
        {
            cin >> a[j];
            vis[a[j]] = true;
        }

        for(int j = a[1]; j <= a[s]; j ++)
        {
            if(!vis[j])
            {
                for(int k = 1; k <= s; k ++)
                {
                    if(g[a[k]][j]) continue;
                    g[a[k]][j] = true;
                    ind[j] ++;
                }
            }
        }
        
    }

    topo(n);

    return 0;
}