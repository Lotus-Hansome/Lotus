/*
本题不能使用贪心的做法
既不能先去找最大连续区间，再去找不重合的次大连续区间
因为先找最大值这可能导致次大连续区间很小，从而不是最优解
比如a=5,b=1,c=4,d=3
找到的最大的为a,然后次大值为b,结果为a+b=6
而c+d=7>a+b
所以正确做法应该是DP
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;

int a[N];
// 定义dpl[i]表示1~i个元素所组成的最长合法子数组长度
// dpr[i]表示i~n个元素所组成的最长合法子数组长度
int dpl[N], dpr[N];

int main()
{
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    for(int l = 1, r = 1; l <= n; l ++)
    {
        while(a[r] <= a[l] + k && r <= n) r ++;
        dpr[l] = r - l;
    }
    
    for(int l = n, r = n; r >= 1; r --)
    {
        while(a[r] <= a[l] + k && l >= 1) l --;
        dpl[r] = r - l;
    }

    for(int i = 1; i <= n; i ++) dpl[i] = max(dpl[i - 1], dpl[i]);
    for(int i = n; i >= 1; i --) dpr[i] = max(dpr[i + 1], dpr[i]);
    
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        ans = max(ans, dpl[i] + dpr[i + 1]);
    }

    cout << ans << '\n';
    return 0;
}