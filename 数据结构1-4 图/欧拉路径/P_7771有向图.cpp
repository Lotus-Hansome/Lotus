#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

struct Node{
    int x, y;

    bool operator<(const Node &u)const{
        return y > u.y;
    }
};

struct Edge{
    int x, ne;
}e[N];
int h[N], idx;
int in[N], out[N];
int path[N], cnt;
int n, m;

void add(int x, int y)
{
    e[idx] = {y, h[x]};
    h[x] = idx;
    idx ++;
    in[y] ++;
    out[x] ++;
}

int findst()
{
    int st = -1, ed = -1;
    for(int i = 1; i <= n; i ++)
    {
        int v = out[i] - in[i];
        if(v > 1 || v < -1 || (v == 1 && st != -1) || (v == -1 && ed != -1)) return -1;
        if(v == 1) st = i;
        if(v == -1) ed = i;
    }

    if((st == -1) ^ (ed == -1)) return -1;
    if(st != -1) return st;

    for(int i = 1; i <= n; i ++)
    {
        if(out[i] > 0) return i;
    }

    return -1;
}

// 递归版Hierholzer算法
void euler(int x)
{
    for(int i = h[x]; ~i; i = h[x])
    {
        h[x] = e[i].ne;
        int y = e[i].x;
        euler(y);
    }

    path[++ cnt] = x;
}

// 有向图迭代版Hierholzer算法
// void euler()
// {
//     int st = findst();
//     if(st == -1) return ;

//     stack<int> stk;
//     stk.push(st);
//     while(stk.size())
//     {
//         int x = stk.top();
//         if(h[x] == -1)
//         {
//             stk.pop();
//             path[++ cnt] = x;
//         }
//         else {
//             int y = e[h[x]].x;
//             h[x] = e[h[x]].ne;
//             stk.push(y);
//         }
//     }
// }

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;

    vector<Node> es(m);
    for(int i = 0; i < m; i ++)
    {
        cin >> es[i].x >> es[i].y;
    }
    
    sort(es.begin(), es.end());
    for(int i = 0; i < m; i ++)
    {
        add(es[i].x, es[i].y);
    }

    int st = findst();
    if(st == -1)
    {
        cout << "No\n";
        return 0;
    }
    else euler(st);

    if(cnt != m + 1) cout << "No\n";
    else {
        for(int i = cnt; i >= 1; i --) cout << path[i] << " ";
        cout << '\n';
    }

    return 0;
}