#include<bits/stdc++.h>
using namespace std;

const int N = 35;
struct Edge{
    int x, ne;
}e[N];
int h[N], idx;
int ind[N];
int seq[N], cnt;
int n, m;
bool vis[N], flag;

void add(int x, int y)
{
    e[idx] = {y, h[x]};
    h[x] = idx;
    idx ++;
    ind[y] ++;
}

void topo()
{
    queue<int> q;
    vector<int> tmp(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        if(!vis[i]) continue;
        if(!ind[i]) q.push(i);
    }

    cnt = 0;
    
    while(q.size())
    {
        if(q.size() > 1) flag = false; // 拓扑排序不唯一
        int x = q.front(); q.pop();
        seq[++ cnt] = x;

        for(int i = h[x]; ~i; i = e[i].ne)
        {
            int y = e[i].x;
            tmp[y] ++;
            if(ind[y] - tmp[y] == 0) q.push(y);
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int tol = 0;
    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        for(int j = 1; j <= 3; j ++)
        {
            char ch; cin >> ch;
            if(j == 1) x = ch - 'A' + 1;
            if(j == 3) y = ch - 'A' + 1;
        }
        add(x, y);
        
        if(!vis[x])
        {
            vis[x] = true;
            tol ++;
        }
        if(!vis[y])
        {
            vis[y] = true;
            tol ++;
        }
    
        flag = true;
        
        topo();
        if(cnt < tol) // 拓扑排序没跑完，说明有环
        {
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
        else if(cnt == n && flag)
        {
            cout << "Sorted sequence determined after " << i << " relations: ";
            for(int j = 1; j <= cnt; j ++)
            {
                char ch = seq[j] + 'A' - 1;
                cout << ch;
            }
            cout << ".";
            return 0;
        }
    }

    cout << "Sorted sequence cannot be determined.";

    return 0;
}