#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e8 - 3;
const int N = 1e5 + 9;

int a[N], b[N];
int pos[N]; // 元素x在b(离散化后)数组中的位置
int c[N]; // a[i]离散化后的值在数组b(离散化后)中的位置
int t[N];
int n;
vector<int> L1, L2;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }   

    while('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void discrete()
{
    sort(L1.begin(), L1.end());
    L1.erase(unique(L1.begin(), L1.end()), L1.end());
    sort(L2.begin(), L2.end());
    L2.erase(unique(L2.begin(), L2.end()), L2.end());
}

int getidx1(int x)
{
    return lower_bound(L1.begin(), L1.end(), x) - L1.begin() + 1;
}

int getidx2(int x)
{
    return lower_bound(L2.begin(), L2.end(), x) - L2.begin() + 1;
}

int lowbit(int x) { return x & -x; }

void modify(int k)
{
    for(int i = k; i <= n; i += lowbit(i)) t[i] ++;
}

int query(int k)
{
    int res = 0;
    for(int i = k; i > 0; i -= lowbit(i)) res += t[i];
    return res;
}

int main()
{
    n = read();
    for(int i = 1; i <= n; i ++) a[i] = read(), L1.push_back(a[i]);
    for(int i = 1; i <= n; i ++) b[i] = read(), L2.push_back(b[i]);

    discrete();

    for(int i = 1; i <= n; i ++)
    {
        int x = getidx2(b[i]);
        pos[x] = i;
    }

    for(int i = 1; i <= n; i ++)
    {
        int x = getidx1(a[i]);
        c[i] = pos[x];
    }

    int ans = 0;
    for(int i = n; i >= 1; i --)
    {
        ans = (ans + query(c[i] - 1)) % MOD;
        modify(c[i]);
    }

    cout << ans << '\n';
    return 0;
}