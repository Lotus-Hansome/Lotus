#include<bits/stdc++.h>
using namespace std;

const int N = 25;
int n;
int x[N], y[N];
int a[N];
bool vis[N];
double ans = 1e9;

double get_dist(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

void dfs(int dep, int _x, int _y, double sum)
{
    if(dep == n)
    {
        ans = min(ans, sum);
        return ;
    }

    for(int i = 1; i <= n; i ++)
    {
        if(vis[i]) continue;
        vis[i] = true;
        double d = get_dist(_x, _y, x[i], y[i]);
        dfs(dep + 1, x[i], y[i], sum + d);
        vis[i] = false;
    }

}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> x[i] >> y[i];
    
    dfs(0, 0, 0, 0);

    cout << fixed << setprecision(2) << ans << '\n';

    system("pause");
    return 0;
}