/*
本题在合并时需要注意，i的根节点可能在n+1~2n中
由于统计时，只统计朋友域中的点，所以如果使用pre[i]==i判集合个数可能导致最后统计到的团体数量偏少
解决方案1:在合并时始终让根节点指向值小的节点
解决方案2:使用vis数组统计1~n中哪些有多少个根节点，如果出现新的根节点，ans++
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
//1~n为朋友域，n+1~2n为敌人域
int pre[N * 2];

int root(int x)
{
    if (pre[x] != x) pre[x] = root(pre[x]);
    return pre[x];
}

void Merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if(rx == ry) return ;

    // if(rx < ry) swap(rx, ry);
    pre[rx] = ry;
}

int main()
{
    int n, m; cin >> n >> m;

    for(int i = 1; i <= 2 * n; i ++) pre[i] = i;

    for(int i = 1; i <= m; i ++)
    {
        char op; cin >> op;
        int x, y; cin >> x >> y;

        if(op == 'F') Merge(x, y); // x 和 y是朋友
        else {
            // 敌人的敌人是朋友
            Merge(x, y + n); // x 和 y的敌人是朋友
            Merge(y, x + n); // y 和 x的敌人是朋友
        }
    }

    int ans = 0;
    bitset<N * 2> vis; 
    for(int i = 1; i <= n; i ++)
    {
        // 统计朋友域中的集合个数
        int rt = root(i);
        if(vis[rt]) continue;
        vis[rt] = true;
        ans ++;
    }

    cout << ans << '\n';
    return 0;
}