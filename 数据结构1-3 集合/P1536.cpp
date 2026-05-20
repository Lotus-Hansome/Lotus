#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
int pre[N];

int root(int x)
{
    return pre[x] = pre[x] == x ? x : root(pre[x]);
}

void merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if(rx == ry) return ;
    pre[rx] = ry;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        for(int i = 1; i <= n; i ++) pre[i] = i;

        for(int i = 1; i <= m; i ++)
        {
            int x, y; cin >> x >> y;
            merge(x, y);
        }

        int ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(pre[i] == i) ans ++;
        }

        cout << ans - 1 << '\n';
    }

    system("pause");
    return 0;
}