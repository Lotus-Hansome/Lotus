/*
本题可以使用正难则反的思想
由于直接求节点u能到达的编号最大的点很难
因为如果直接去跑dfs是跑不出答案的
因为u和v之间的联通性不一定是单向的，所以u能到v，v也可能可以到u
而跑dfs只能统计到一个点的所能到达的最大点，另一个点能到达的最大点不一定能统计到

可以逆向建边，然后从编号大的点u去遍历，跟这个点联通的其他点能到达的最大点都是u
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int f[N];// f[x]表示从x出发能走到的编号最大的点

void dfs(int x, int mx)
{
    f[x] = mx;
    for(const auto &y : g[x])
    {
        if(f[y] == 0) dfs(y, mx);
    }
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    {
        int x, y; cin >> x >> y;
        g[y].push_back(x);
    }
    
    for(int i = n; i >= 1; i --)
    {
        if(f[i] == 0) dfs(i, i);
    }
    
    
    for(int i = 1; i <= n; i ++) cout << f[i] << " ";

    return 0;
}