/*
本题使用模拟也可以解决，但这里用离散化+差分的方法做一下
在这题中，其实我们并不需要去区分起点和终点
有n条线段，每条线段有一个起点和终点，总共2n个点
我们可以将这2n个点按坐标从小到大排序那么只需考虑每个相邻坐标是否有覆盖即可
这个时候就可以用差分数组来解决了，但由于值域比较大，所以需要先离散化
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 4e4 + 9;

vector<pair<int, int>> segs;
vector<int> L;
int diff[N];

void discrete()
{
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
}

int get_idx(int x)
{
    return lower_bound(L.begin(), L.end(), x) - L.begin();
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int a, b; cin >> a >> b;
        segs.push_back({a, b});
        L.push_back(a);
        L.push_back(b);
    }

    discrete();

    for(const auto &seg : segs)
    {
        int l = get_idx(seg.first);
        int r = get_idx(seg.second);
        diff[l] ++;
        diff[r] --;
    }

    int ans = 0, sum = 0;
    for(int i = 0; i < L.size() - 1; i ++)
    {
        sum += diff[i]; // sum > 0，说明这个点和后面的点坐标-1组成的这条线段在坐标轴上有覆盖
        if(sum > 0)
        {
            // 区间长度为右端点(开)-左端点，由于右端点是开，所以不需要+1
            ans += L[i + 1] - L[i];
        }
    }

    cout << ans << '\n';
    return 0;
}