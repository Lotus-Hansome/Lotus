#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int pre[N];

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int a; cin >> a;
        pre[i] = pre[i - 1] + a;
    }

    int m; cin >> m;
    while(m --)
    {
        int l, r; cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
    return 0;
}