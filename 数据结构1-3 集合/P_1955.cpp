/*
要注意这题不能使用扩展域并查集来做
因为相等关系具有传递性，而不等关系不满足传递性
而使用并查集需要满足传递性
如果使用扩展域并查集，1~n为相等域,n+1~2n为不等域
举个例子，x1!=x2
但x1与x2+n(不等于x2的数)不一定属于同一个集合
假设x3!=x2，那么也就是说x1可以等于x3，x1也可以等于x3
也就是不能合并属于x1的集合与属于x2+n的集合
所以使用扩展域并查集会出错
9
3 7 1
14 1 1
9 5 0
2 1 1
6 12 0
10 4 1
8 11 0
8 13 0
11 13 0
如果使用扩展域并查集会输出NO，而正确答案为YES
原因就是
8 11
8 13
11 13
是不等关系不能合并，而使用扩展域并查集后就会将8跟8+m合并，导致答案错误

这题使用普通并查集就能做
有与相等关系满足传递性，所以我们只需维护一个满足相等关系的集合
在判断每个不等关系的两个元素是否在这个集合里，如果在，就输出NO，反之输出YES
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int pre[N];

struct Node{
    int x, y, op;

    bool operator<(const Node &u)const{
        return op > u.op;
    }
}node[N];

vector<int> L;
int n, m;

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void Merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if(rx == ry) return ;
    pre[rx] = ry;
}

void discrete()
{
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    m = L.size();
    for(int i = 1; i <= n; i ++)
    {
        node[i].x = lower_bound(L.begin(), L.end(), node[i].x) - L.begin() + 1;
        node[i].y = lower_bound(L.begin(), L.end(), node[i].y) - L.begin() + 1;
    }
}

void solve()
{
    cin >> n;
    L.clear();

    for(int i = 1; i <= n; i ++)
    {
        cin >> node[i].x >> node[i].y >> node[i].op;
        L.push_back(node[i].x);
        L.push_back(node[i].y);
    }
    
    discrete();
    sort(node + 1, node + 1 + n);

    for(int i = 1; i <= m; i ++) pre[i] = i;

    bool flag = true;
    for(int i = 1; i <= n; i ++)
    {
        int x = node[i].x, y = node[i].y;
        if(node[i].op == 1) Merge(x, y);
        else {
            if(root(x) == root(y))
            {
                flag = false;
                break;
            }
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    int _; cin >> _;
    while(_ --) solve();
    return 0;
}