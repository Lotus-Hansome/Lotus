/*
要使分配后爆发冲突的影响力的最大值最小
那么我们先去处理怨气值大的囚犯，尽量让两个怨气值大的囚犯分在不同的监狱里
如果可以，我们继续处理下一个更小的怨气值的囚犯，看是否还能将这两个囚犯分在不同的监狱里
如果不可以，这就是最大的影响力（答案）
n 个点有 m 对关系，把 n 个节点放入两个集合里，要求每对存在关系的两个节点不能放在同一个集合。问能否成功完成？
可以使用扩展与并查集解决
拓展域并查集，主要用于一种状态表示无法解决问题的题目。例如本题，一个开关有两种状态，用和不用。
定义1~n为i的同类域，1+n~2n为i的相反状态
对于两个囚犯u,v 我们让他们不在一个监狱里，也就是u和v不在一个集合里
也就是将u和v的反状态关在一个监狱里，v和u的反状态关在一个监狱里
当u和u的反状态或v和v的反状态在一个监狱里时，说明此时无法将u，v放在不同监狱里，因此输出答案

也可以这样理解，i表示把囚犯i放在某个监狱中，i+n表示把囚犯关在与i相反的监狱中
比如i在监狱A，i+n表示把i放在监狱B中
u，v不能在同一个监狱里也就是说
u放在监狱A中，那么v就要放在监狱B中，所以u和v+n是同一类，合并(u, v+n)
v放在监狱A中，那么u就要放在监狱B中，所以v和u+n也是同一类，所以也要合并(v, u+n)
如果u和u+n在同一个集合里或v和v在同一个集合里，那么就矛盾了，也就是此时u和v只能放在同一个监狱里
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int pre[400005];
struct Node{
    int x, y, c;

    bool operator<(const Node &u)const{
        return c > u.c;;
    }
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
    for(int i = 1; i <= m; i ++) cin >> a[i].x >> a[i].y >> a[i].c;
    sort(a + 1, a + 1 + m);
    
    for(int i = 1; i <= 2 * n; i ++) pre[i] = i;

    int id = 0;
    for(int i = 1; i <= m; i ++)
    {
        int x = a[i].x, y = a[i].y;
        Merge(x, y + n);
        Merge(y, x + n);
        if(root(x) == root(x + n) || root(y) == root(y + n))
        {
            id = i;
            break;
        }
    }

    cout << a[id].c << '\n';

    system("pause");
    return 0;
}