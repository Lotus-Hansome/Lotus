/*
每把钥匙都有两种状态，使用或不使用
用i(1~n)表示使用，i+n(n+1~2n)表示不使用
每个房间都有且仅有两把钥匙(u, v)控制
如果房间一开始是开的，要让最后房间也是开的，那么这两把钥匙只能都使用或者都不用，即合并(u, v), (u + n, v + n)
如果房间一开始是关的，要让最后房间也是开的，那么这两把钥匙只能使用其中一把，即合并(u, v + n), (v, u + n)
最后遍历一遍所有钥匙，如果钥匙的i和n+i联通，这说明没有一种切换开关的方式，使得所有门同时被打开
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int r[N];
int pre[N];
struct Node{
    int x, y;
}a[N];

int root(int x)
{
    return pre[x] = pre[x] == x ? x : root(pre[x]);
}

void Merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if(rx == ry) return ;
    pre[rx] = ry;
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> r[i];
 
    for(int i = 1; i <= 2 * m; i ++) pre[i] = i;

    for(int i = 1; i <= m; i ++)
    {
        int t; cin >> t;
        while(t --)
        {
            int id; cin >> id;
            if(a[id].x == 0) a[id].x = i;
            else a[id].y = i;
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        int x = a[i].x, y = a[i].y;
        if(r[i] == 1)
        {
            Merge(x, y);
            Merge(x + m, y + m);
        }
        else {
            Merge(x, y + m);
            Merge(y, x + m);
        }
    }

    bool flag = true;
    for(int i = 1; i <= m; i ++)
    {
        if(root(i) == root(i + m))
        {
            flag = false;
            break;
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;   
}