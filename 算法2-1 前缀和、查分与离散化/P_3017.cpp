/*
也是终于靠自己做出来了一道蓝题了！！！（虽然还是看了一眼标签）
分析题目:要求最小值最大，很容易想到二分去求解
只不过这题是一个二维数组，所以需要使用二维前缀和
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 500;

int a[N][N];
int sum[N][N];
int n, m, A, B; 

int getsum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

bool check(int x)
{
    int len = 0;
    int r = 0, last = 1;
    for(int i = 1; i <= n; i ++)
    {
        // 第last行到第i行能分多少列,tol用来记录当前列内和为多少
        int tol = 0, c = 0;
        for(int j = 1; j <= m; j ++)
        {
            tol = getsum(last, j, i, j);
            while(tol < x && j < m)
            {
                j ++;
                tol += getsum(last, j, i, j);
            }
            
            if(tol >= x) c ++;
        }

        // 看第last行到第i行能分成的列是否>=B
        // 如果可以，就在第i行到第i+1行划一刀
        // 同时行数r++
        if(c >= B)
        {
            r ++;
            last = i + 1;
        }
    }

    return r >= A;
}

int main()
{
    cin >> n >> m >> A >> B;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    int l = 0, r = 1e9 + 1, ans = 0;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << ans << '\n';
    return 0;
}