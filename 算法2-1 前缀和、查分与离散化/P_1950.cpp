/*
本题和P4147有点像
首先，合法的剪矩形的方案数等于全为'.'的矩形数量
那么怎么去求总数量呢，还是先考虑一个一维问题
有一个x轴（地面），在x轴（地面）上排列有很多高度不同宽度为1的矩形
应该怎么求出所有的矩形数量呢
可以当前高度为h坐标为i的矩形，可以去求出它左边第一个高度不大于(<=)它的矩形的坐标l作为左边界
求出它右边第一个高度小于它的矩形的坐标r作为右边界，然后总共有h*(i-l)*(r-i)种矩形
这样求出来的矩形数量不会重复，因为对于每个矩形，我们只算它和比它大的矩形所构成的矩形的数量
为什么要取左边第一个高度不大于(<=)它的矩形和右边第一个高度小于他的矩形的坐标呢？
也是为了保证不重复计算，这样对于该矩形前面的和他高度相等的矩形它就不会再和该矩形产生贡献
因为在在计算前面和他高度相等的矩形的贡献时就已经计算了该矩形和它之间矩形的贡献
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 9;

char mp[N][N];

int h[N];
int stk[N], top;
int dp1[N], dp2[N];

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> mp[i][j];
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(mp[i][j] == '*') h[j] = 0;
            else h[j] ++;
        }

        top = 0;
        for(int j = 1; j <= m; j ++)
        {
            while(top && h[stk[top]] > h[j]) top --;
            if(!top) dp1[j] = 0;
            else dp1[j] = stk[top];
            stk[++ top] = j;
        }

        top = 0;
        for(int j = m; j >= 1; j --)
        {
            while(top && h[stk[top]] >= h[j]) top --;
            if(!top) dp2[j] = m + 1;
            else dp2[j] = stk[top];
            stk[++ top] = j;
        }

        for(int j = 1; j <= m; j ++)
        {
            ans += 1ll * (j - dp1[j]) * (dp2[j] - j) * h[j];
        }
    }

    cout << ans << '\n';
    return 0;
}