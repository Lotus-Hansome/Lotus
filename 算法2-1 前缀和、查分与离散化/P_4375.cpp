/*
本题需要离散化处理，但不是常规的离散化（即不能去除重复的元素后离散化）
对数组进行稳定排序（数值相同则按原下标升序），将每个元素映射到它在排序后数组中的位置（1-based）
离散化后，每一轮从左到右扫描会把比位置x大的元素移到x右边
从右往左扫描会把比位置x小的元素移到x左边
离散化后，答案就是max(i=1~n)∑(j=1~i)[a[j]>i]
这个式子其实就是在 [1,i] 中不属于这个区间的数的个数。
每一次如果 [1,i] 没有排序好，左冒泡走掉的肯定不属于这个区间，并且右冒泡肯定会补回来一个，
所以单独对于这个区间来说就需要 ∑(j=1~i)[a[j]>i]次
那么排序，就是要对任意的 i，下标为 [1,i] 的数当中只有 [1,i] 所以结论得证。
从左到右遍历数组，对于每个位置i，统计前 i 个元素中，应该在 i 右边的元素个数（即映射后的值大于 i 的元素个数）
这些个数的最大值就是需要的轮数；如果数组已经有序，仍需输出 1 次moo
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

struct Node
{
    int num, id;
}a[N];

int t[N];
int n;

bool cmp1(const Node& a, const Node& b) 
{
    return a.num == b.num ? a.id < b.id : a.num < b.num;
}

bool cmp2(const Node& a, const Node& b) 
{
    return a.id < b.id;
}

int lowbit(int x) 
{
    return x & -x;
}

void add(int x, int val) 
{
    for (int i = x; i <= n; i += lowbit(i))
        t[i] += val;
}

int query(int x)
{
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) res += t[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) 
    {
        cin >> a[i].num;
        a[i].id = i;
    }
    
    sort(a + 1, a + n + 1, cmp1);
    for(int i = 1; i <= n; ++i) a[i].num = i;
    
    sort(a + 1, a + n + 1, cmp2);
    
    int ans = 1;
    for(int i = 1; i <= n; ++i) 
    {
        add(a[i].num, 1);
        int cnt = i - query(i);
        ans = max(ans, cnt);
    }
    
    cout << ans << '\n';
    return 0;
}