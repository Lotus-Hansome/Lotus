#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;

int a[N];

bool cmp(int x, int y)
{
    return a[x] == a[y] ? x < y : a[x] > a[y];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    bool flag = true;
    int id = 0;
    while(q --)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int x, v; cin >> x >> v;
            a[x] = v;
        }
        else
        {
            int x; cin >> x;
            int pos = n;
            for(int i = 1; i < x; i ++) if(a[i] > a[x]) pos --;
            for(int i = x + 1; i <= n; i ++) if(a[i] >= a[x]) pos --;
            cout << pos << '\n';
        }
    }

    return 0;
}