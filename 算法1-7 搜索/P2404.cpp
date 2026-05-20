#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int a[N];
int n;

// 选了dep个数，总和为sum
void dfs(int dep, int sum)
{
    if(sum == n)
    {
        if(dep == 1) return ;
        for(int i = 1; i <= dep - 1; i ++) cout << a[i] << "+";
        cout << a[dep] << '\n';
        return ;
    }
    
    for(int i = max(1, a[dep]); i <= n - sum; i ++)
    {
        a[dep + 1] = i;
        dfs(dep + 1, sum + i);
    }   
}

int main()
{
    cin >> n;

    dfs(0, 0);

    system("pause");

    return 0;
}