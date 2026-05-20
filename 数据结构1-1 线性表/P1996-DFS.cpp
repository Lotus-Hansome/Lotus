#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N];

// 有n个人，数到m出列，求第i个出列的人的序号(从0开始)
int dfs(int n, int m, int i)
{
    if(i == 1) return (m - 1 + n) % n;
    else return (dfs(n - 1, m, i - 1) + m) % n;
}

int main()
{
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i ++) cout << dfs(n, m, i) + 1 << " ";
    
    system("pause");
    return 0;
}