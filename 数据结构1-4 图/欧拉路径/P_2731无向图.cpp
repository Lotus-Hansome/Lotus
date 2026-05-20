#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 9;

struct Edge{
    int x, ne, id;
}e[N];
int h[N], idx;
int path[N], cnt;
int deg[N];
bool vis[N];
int n = 500, m;

struct Node{
    int x, id;

    // 将每个点的邻接点降序排序
    // 由于是头插法插入边，所以该点的邻接点中编号小的点会插在前面
    bool operator<(const Node &u)const{
        return x > u.x; 
    }
};
vector<Node> adj[N];// 存储每个点的邻接点

void add(int x, int y, int id)
{
    e[idx] = {y, h[x], id};
    h[x] = idx;
    idx ++;
    deg[x] ++;
}

int findst()
{
    int odd = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(deg[i] & 1) odd ++;
    }
    
    if(odd != 0 && odd != 2) return -1;
    
    for(int i = 1; i <= n; i ++)
    {
        if(odd == 0 && deg[i] > 0) return i;
        if(odd == 2 && (deg[i] & 1)) return i;
    }

    return -1;
}

// 无向图Hierholzer算法递归版
// void euler(int x)
// {
//     for(int i = h[x]; ~i; i = h[x])
//     {
//         h[x] = e[i].ne;
//         if(!vis[e[i].id])
//         {
//             vis[e[i].id] = true;
//             int y = e[i].x;
//             euler(y);
//         }
//     }
//     path[++ cnt] = x;
// }

// 无向图Hierholzer算法迭代版
void euler(int st)
{
    stack<int> stk;
    stk.push(st);
    while(stk.size())
    {
        int x = stk.top();
        if(h[x] != -1)
        {
            int y = e[h[x]].x, id = e[h[x]].id;
            h[x] = e[h[x]].ne;
            if(!vis[id])
            {
                vis[id] = true;
                stk.push(y);
            }
        }else {
            stk.pop();
            path[++ cnt] = x;
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> m;

    for(int i = 0; i < m; i ++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for(int x = 1; x <= n; x ++)
    {
        if(!adj[x].size()) continue;
        sort(adj[x].begin(), adj[x].end());
        for(const auto t : adj[x])
        {
            int y = t.x, id = t.id;
            add(x, y, id);
        }
    }
    
    int st = findst();
    
    euler(st);
    
    for(int i = cnt; i >= 1; i --) cout << path[i] << "\n";

    return 0;
}