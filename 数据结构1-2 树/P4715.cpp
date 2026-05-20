#include<bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int N = 130;
PII t[N << 2];

void pushup(int o)
{
    t[o] = max(t[o << 1], t[o << 1 | 1]);
}

void build(int s, int e, int o)
{
    if(s == e)
    {
        int x; cin >> x;
        t[o] = make_pair(x, s);
        return ;
    }

    int mid = s + e >> 1;
    build(s, mid, o << 1);
    build(mid + 1, e, o << 1 | 1);
    pushup(o);
}

int main()
{
    int n; cin >> n;
    build(1, (1 << n), 1);
    PII ans = min(t[2], t[3]);
    cout << ans.second << '\n';
    
    system("pause");
    return 0;
}