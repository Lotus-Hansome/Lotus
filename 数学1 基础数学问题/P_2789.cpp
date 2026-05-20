/*
假设有n条相交的直线，他们的交点数为0
如果插入1条直线与他们相交，那么会产生n个交点
如果插入两条直线与他们相交，且这两条直线互相平行，那么会产生的交点为2*n
由于只有相交的直线会产生交点，我们可以将相互平行的直线划分为一类
假设有n类直线，每一类的个数为a1, a2, a3, ...... , an-1, an
他们产生的交点数该怎么计算呢
假设已经有k-1类直线了，且这k-1类直线的所包含的直线总数量为sk-1
插入第k类直线，假设这类直线包含ak条直线
那么他能与前k-1类直线新产生的交点数量为sk-1 * ak(不考虑三点共线)
因为要保证他与前面所有直线都不属于同一类，那么他需要和前面k-1类直线都相交，每条都产生sk-1个交点，共ak条
所以新增交点数为sk-1*ak
如果知道直线数量，就可以用递推来求解他们所能产生的交点数有哪些了
*/
#include<bits/stdc++.h>
using namespace std;

// n条直线所能产生交点树最多为n*(n-1)/2
const int N = 1e3 + 9;

int n;
bool f[N]; 

// sum为前i-1种直线数量，tol为他们所能产生交点数量
void dfs(int sum, int tol)
{
    if(sum == n) f[tol] = true;
    for(int i = 1; i <= n - sum; i ++)
    {
        dfs(sum + i, i * sum + tol);
    }

}

int main()
{
    cin >> n;
    dfs(0, 0);
    int ans = 0;
    for(int i = 0; i <= n * n; i ++)
    {
        if(f[i]) ans ++;
    }

    cout << ans << '\n';
    return 0;
}