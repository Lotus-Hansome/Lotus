/*
本题需要用到扩展域并查集和离散化
设01序列的前缀和为sum,即sum[i]表示1~i中1的个数
如果区间[l,r]的中1的个数为奇数个
那么sum[r]-sum[l-1]就为奇数，即sum[l-1]与sum[r]奇偶性相反
同理[l,r]中1的个数为偶数个，那么sum[l-1]与sum[r]奇偶性相同
假设x与y奇偶性相同，那么与x奇偶性相同的一定与y奇偶性相同，与x奇偶性相反的数一定和与y奇偶性相反的数相同
假设x与y奇偶性相反，那么与x奇偶性相同的一定与y奇偶性相反的相同，与x奇偶性相反的一定与y奇偶性相同
所以奇偶性满足传递性，同时需要维护两个关系，所以用扩展域并查集求解
此外，由于值域过大，需要离散化处理
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 9;

struct Node{
    int x, y;
    string s;
}a[N];

vector<int> L;
int n, m;
int k;
int pre[N * 2];

void discrete()
{
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    k = L.size();
    for(int i = 1; i <= m; i ++)
    {
        a[i].x = lower_bound(L.begin(), L.end(), a[i].x) - L.begin() + 1;
        a[i].y = lower_bound(L.begin(), L.end(), a[i].y) - L.begin() + 1;
    }
}

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
    cin >> n >> m;
    
    for(int i = 1; i <= m; i ++)
    {
        cin >> a[i].x >> a[i].y >> a[i].s;
        a[i].x --; // l=l-1
        L.push_back(a[i].x);
        L.push_back(a[i].y);
    }

    discrete();
    for(int i = 1; i <= 2 * k; i ++) pre[i] = i;

    int ans = m;
    for(int i = 1; i <= m; i ++)
    {
        int x = a[i].x, y = a[i].y;

        if(a[i].s == "odd") // x与y奇偶性不同
        {
            // 与x奇偶性不同的数和y奇偶性相同
            merge(x + k, y);
            // 与y奇偶性不同的数和x奇偶性相同
            merge(x, y + k);
            // if(root(x) == root(y) || root(x + k) == root(y + k))
            // {
            //     ans = i - 1;
            //     break;
            // }
        }
        else // x与y奇偶性相同 
        {
            // x与y奇偶性相同
            merge(x, y);
            // 与x奇偶性相反的数和与y奇偶性相反的数奇偶性相同
            merge(x + k, y + k);
            // if(root(x) == root(y + k) || root(x + k) == root(y))
            // { 
            //     ans = i - 1;
            //     break;
            // }
        }

        // 可以注释写法交换
        if(root(x) == root(x + k) || root(y) == root(y + k))
        {
            ans = i - 1;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}