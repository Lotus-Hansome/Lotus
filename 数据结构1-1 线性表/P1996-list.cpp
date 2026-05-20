#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int pre[N], nxt[N];

void del(int x)
{
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        if(i == 1) pre[i] = n;
        else pre[i] = i - 1;
        
        if(i == n) nxt[i] = 1;
        else nxt[i] = i + 1;
    }

    int idx = 1;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m - 1; j ++) idx = nxt[idx];
        cout << idx << " ";
        del(idx);
        idx = nxt[idx];
    }

    system("pause");
    return 0;
}