/*
设ans[i]为从n中选i个数所能获得的最大公因子，本题要将i从1到n中的ans[i]都求出来
可以统计出这些数所拥有的因子个数，然后再枚举每个因数x，只要x的次数>=k，
就说明可以选出j(j<=k)个同学，这j个同学的最大公因子为x
本题不能预处理出所有数的因子，会超时，因为inf=1e6
但是n只有1e4，而枚举数inf的因子时间复杂度为sqrt(inf)
所以可以对于每个数，可以直接枚举他的因子，然后统计他的因子个数
因为要求最大默契程度，所以从大到小枚举因子
设当前因子个数为k，如果ans[k]不为0，说明j(j<=k)都被前面更大的因子更新过了
否则去遍历j(1<=j<=k)，看哪些数还没有值，就去更新
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int ans[10005];
int cnt[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    // 时间复杂度为O(n*sqrt(inf))
    for(int i = 1; i <= n; i ++)
    {
        int x; cin >> x;
        for(int j = 1; j <= x / j; j ++)
        {
            if(x % j) continue;
            cnt[j] ++;
            if(x / j != j) cnt[x / j] ++;
        }
    }

    for(int i = N - 1; i >= 1; i --)
    {
        int k = cnt[i];
        if(ans[k]) continue;
        for(int j = 1; j <= k; j ++)
        {
            if(ans[j] == 0) ans[j] = i;
        }
    }

    for(int i = 1; i <= n; i ++) cout << ans[i] << '\n';
    return 0;
}