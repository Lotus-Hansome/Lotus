/*
这是一道经典的最大子矩形问题，有两种方法，一种是悬线法，一种是枚举障碍点
本题数据范围适合用枚举障碍点法
定义极大子矩形为4条边都不能向外拓展的有效子矩形（这里的有效即子矩形内不包括障碍点)。
可以得到最大子矩形是所有极大子矩形中最大的，所以只要枚举最大的子矩形，求出其中最大的即可
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 9;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }

    while('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }

    return x * f;
}

struct Node{
    int x, y;
}pos[N];

// 按横坐标排序
bool cmpx(Node a, Node b)
{
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}

// 按纵坐标排序
bool cmpy(Node a, Node b)
{
    return a.y == b.y ? a.x < b.x  : a.y < b.y;
}

int main()
{
    int L, W; cin >> L >> W;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        pos[i].x = read();
        pos[i].y = read();
    }
    pos[++ n].x = 0, pos[n].y = 0;
    pos[++ n].x = 0, pos[n].y = W;
    pos[++ n].x = L, pos[n].y = 0;
    pos[++ n].x = L, pos[n].y = W;

    int x1, x2, y1, y2;
    sort(pos + 1, pos + 1 + n, cmpx);

    int ans = 0;

    // 从左往右扫，枚举每个点为矩形左边界时所对应的极大子矩形
    for(int i = 1; i <= n; i ++)
    {
        x1 = pos[i].x, y1 = 0, y2 = W;
        for(int j = i + 1; j <= n; j ++)
        {
            x2 = pos[j].x;
            ans = max(ans, (x2 - x1) * (y2 - y1));
            if(pos[j].y < pos[i].y) y1 = max(y1, pos[j].y);
            else y2 = min(y2, pos[j].y);
        }
    }

    // 由于从左往右扫会漏掉一种以障碍点为右边界的极大子矩形的情况
    // 所以还要从右往左扫，枚举每个点为边界时所对应的极大子矩形
    for(int i = n; i >= 1; i --)
    {
        x1 = pos[i].x, y1 = 0, y2 = W;
        for(int j = i - 1; j >= 1; j --)
        {
            x2 = pos[j].x;
            ans = max(ans, (x1 - x2) * (y2 - y1));
            if(pos[j].y < pos[i].y) y1 = max(y1, pos[j].y);
            else y2 =  min(y2, pos[j].y);
        }
    }

    // 还有一种情况，就是极大子矩形的左右边界为牛场的左右边界
    sort(pos + 1, pos + 1 + n, cmpy);
    for(int i = 1; i <= n - 1; i ++)
    {
        ans = max(ans, L * (pos[i + 1].y - pos[i].y));
    }

    cout << ans << '\n';   
    return 0;
}