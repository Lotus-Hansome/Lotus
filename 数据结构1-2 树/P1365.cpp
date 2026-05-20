#include<bits/stdc++.h>
using namespace std;

const int N = 105;
struct Node{
    int ls, rs, val;
}tree[N];

int dep[N], siz[N], dp[N], tol;

void dfs1(int x)
{
    siz[x] = tree[x].val;

    if(tree[x].ls)
    {
        dep[tree[x].ls] = dep[x] + 1;
        dfs1(tree[x].ls);
        siz[x] += siz[tree[x].ls];
    }
    if(tree[x].rs)
    {
        dep[tree[x].rs] = dep[x] + 1;
        dfs1(tree[x].rs);
        siz[x] += siz[tree[x].rs];
    }
}

void dfs2(int x)
{
    if(tree[x].ls)
    {
        dp[tree[x].ls] = dp[x] - 2 * siz[tree[x].ls] + tol;
        dfs2(tree[x].ls);
    }

    if(tree[x].rs)
    {
        dp[tree[x].rs] = dp[x] - 2 * siz[tree[x].rs] + tol;
        dfs2(tree[x].rs);
    }
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> tree[i].val >> tree[i].ls >> tree[i].rs;
        tol += tree[i].val;
    }

    dfs1(1);
    for(int i = 1; i <= n; i ++) dp[1] += dep[i] * tree[i].val;

    dfs2(1);
    int ans = INT_MAX;
    for(int i = 1; i <= n; i ++) ans = min(ans, dp[i]);
    cout << ans << '\n';

    system("pause");
    return 0;
}