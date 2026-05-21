/*
考虑这样一个一维问题
有一个x轴（地面），在x轴（地面）上排列有很多高度不同宽度为1的矩形
应该怎么求能组成的矩形的最大面积呢
可以枚举每一个矩形，由该矩形高度h所组成的面积最大的矩形的宽度为
左边第一个高于它的矩形的与右边第一个高于他的矩形的距离d
所以他能组成的最大矩形面积为h*d，然后再取最大值即可

现在题目换成了一个二维数组，也就是一个二维问题
可以枚举每一行作为地面，然后求改行作为地面时的最大矩形面积的操作和上述相同
然后再取最大值即可
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;

char mp[N][N];
int h[N]; // h[i][j]表示第i行第j列以j为地面的柱子的高度,可以用滚动数组优化掉一维
int stk[N], top; // 单调栈
int dp1[N], dp2[N]; // dp1[i]表示左边第一个比当前高的矩形的横坐标，dp2[i]表示右边第一个比当前高的矩形的横坐标

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

    int ans = 0;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(mp[i][j] == 'R') h[j] = 0;
            else h[j] = h[j] + 1;
        }

        top = 0;
        for(int j = 1; j <= m; j ++)
        {
            while(top && h[stk[top]] >= h[j]) top --;
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
            int s = (dp2[j] - dp1[j] - 1) * h[j];
            ans = max(ans, s);
        }
    }

    cout << ans * 3 << '\n';
    return 0;
}