/*
要使分配后爆发冲突的影响力的最大值最小
考虑使用贪心和二分
我们肯定要让怨气值大的两个人分在不同的监狱
对于某个怨气值，我们怎么判断是否有一种分配方式可以让分配后爆发冲突的影响力都不大于它呢
可以让怨气值大于该影响力的两个囚犯建边，要将他们分在不同的集合里，而怨气值小于该影响力的囚犯分在一个监狱里
可以发现这就是一个二分图
所以我们判断是否可以分配成功只需判断建边后的图是不是一个二分图
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

struct Node{
    int x, y, c;

    bool operator<(const Node &u)const{
        return c < u.c;
    }
}a[N];

int n, m;
vector<int> g[N];
int col[N];

// 判断有无奇环
bool dfs(int x, int c)
{
    col[x] = c;
    for(const auto y : g[x])
    {
        if(!col[y])
        {
            if(dfs(y, 3 - c)) return true;
        }
        else
        {
            if(col[x] == col[y]) return true;
        }
    }

    return false;
}

// 判断是否为二分图
bool check(int pos)
{
    memset(col, 0, sizeof col);
    for(int i = 1; i <= n; i ++) g[i].clear();
    for(int i = pos + 1; i <= m; i ++)
    {
        g[a[i].x].push_back(a[i].y);
        g[a[i].y].push_back(a[i].x);
    }

    for(int i = 1; i <= n; i ++)
    {
        if(col[i]) continue;
        if(dfs(i, 1)) return false;
    }

    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) cin >> a[i].x >> a[i].y >> a[i].c;

    sort(a + 1, a + 1 + m);

    int l = 0, r = m, ans = 0;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << a[ans].c << '\n';

    system("pause");
    return 0;
}