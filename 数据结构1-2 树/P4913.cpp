#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
struct Node{
    int l, r;
}t[N];
int ans = 0;

void dfs(int dep, int id)
{
    if(id == 0) return ;

    ans = max(ans, dep);
    dfs(dep + 1, t[id].l);
    dfs(dep + 1,t[id].r);
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> t[i].l >> t[i].r;
    dfs(1, 1);

    cout << ans << '\n';

    system("pause");
    return 0;
}