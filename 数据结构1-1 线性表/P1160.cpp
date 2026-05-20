#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int pre[N], nxt[N];
int hd = 100001, til = 100002;
bool in[N];

void insert_front(int x, int y)
{
    pre[y] = pre[x], nxt[y] = x;
    nxt[pre[x]] = y, pre[x] = y;
}

void insert_back(int x, int y)
{
    pre[y] = x, nxt[y] = nxt[x];
    pre[nxt[x]] = y, nxt[x] = y;
}

void del(int x)
{
    if(!in[x]) return ;
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
    in[x] = false;
}

int main()
{
    int n; cin >> n;
    nxt[hd] = til, pre[til] = hd;
    insert_back(hd, 1);
    in[1] = true;
    
    for(int i = 2; i <= n; i ++)
    {
        int k, p; cin >> k >> p;
        if(p == 0) insert_front(k, i);
        else insert_back(k, i);

        in[i] = true;
    }

    int m; cin >> m;
    for(int i = 1; i <= m; i ++)
    {
        int x; cin >> x;
        del(x);
    }

    for(int i = nxt[hd]; i != til; i = nxt[i]) cout << i << " ";

    system("pause");
    return 0;
}