/*
本题是P1496火烧赤壁的二维形式
需要结合扫描线算法解决
也可以使用二维差分，不过二维差分占用空间比较大
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 9;

// 画一条横线，从下往上依次计算面积
struct Line{ // 扫描线
    int x1, x2, y;
    int tag; // 入边+1, 出边-1
    // 按y从小到大排序
    bool operator<(const Line &u)const{
        return y < u.y;
    }
}line[2 * N];
vector<int> X; // x坐标，后续进行离散化
int diff[2 * N];

// 离散化
void discrete()
{
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
}

// 取下标
int get_idx(int x)
{
    return lower_bound(X.begin(), X.end(), x) - X.begin();
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) 
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        line[i] = {x1, x2, y2, 1}; 
        line[n + i] = {x1, x2, y1, -1}; 
        X.push_back(x1);
        X.push_back(x2);
    }  

    sort(line + 1, line + 1 + 2 * n);
    discrete();
    
    ll ans = 0;
    int last_y = line[1].y;

    for(int i = 1; i <= 2 * n; i ++)
    {
        if(line[i].y > last_y)
        {
            ll dy = line[i].y - last_y;
            ll wid = 0, sum = 0;
            for(int j = 0; j < X.size() - 1; j ++)
            {
                sum += diff[j];
                if(sum > 0) wid += ll(X[j + 1]) - X[j];
            }

            ans += dy * wid; // 面积等于长乘以宽度
        }

        int l = get_idx(line[i].x1);
        int r = get_idx(line[i].x2);

        // 对于每条边，把[x1, x2)的值都加上tag，表示下面这条边把x轴有覆盖了一次
        // 或者上面的边表示该矩形对x轴影响已经结束
        diff[l] += line[i].tag;
        diff[r] -= line[i].tag;
        last_y = line[i].y;
    }

    cout << ans << '\n';
    return 0;
}