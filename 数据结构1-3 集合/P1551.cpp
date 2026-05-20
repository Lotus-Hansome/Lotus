#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 9;
int pre[N];

int root(int x)
{
    return (pre[x] = pre[x] == x ? x : root(pre[x]));
}

void merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if(rx == ry) return ;

    pre[rx] = ry;
}

int main()
{
    int n, m, p; cin >> n >> m >> p;

    for(int i = 1; i <= n; i ++) pre[i] = i;

    for(int i = 1; i <= m; i ++)
    {
        int x, y; cin >> x >> y;
        merge(x, y);
    }

    for(int i = 1; i <= p; i ++)
    {
        int x, y; cin >> x >> y;
        if(root(x) == root(y)) cout << "Yes\n";
        else cout << "No\n";
    }

    system("pause");
    return 0;
}