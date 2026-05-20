#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

bool vis[N];
int pre[N];

int root(int x)
{
    return pre[x] = pre[x] == x ? x : root(pre[x]);
}

void Merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    // 始终让根指向大的点，因为小的质数可能不在范围内，会导致结果统计错误
    if(rx  > ry) swap(rx, ry);
    if(rx == ry) return ;
    pre[rx] = ry;
}

int main()
{
    int a, b, p; cin >> a >> b >> p;
    for(int i = 1; i <= b; i ++) pre[i] = i;

    vis[0] = vis[1] = true;
    for(int i = 2; i <= b; i ++)
    {
        if(!vis[i])
        {
            for(int j = i * 2; j <= b; j += i)
            {
                vis[j] = true;
                if(i >= p) Merge(i, j);
            }
        }
    }

    int ans = 0;
    for(int i = a; i <= b; i ++)
    {
        //if(pre[i] == i) cout << i << '\n';
        if(pre[i] == i) ans ++;
    }

    cout << ans << '\n';
    return 0;
}