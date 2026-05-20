#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 9;
int a[N], d[N];

int main()
{
    int n, p; cin >> n >> p;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) d[i] = a[i]- a[i - 1];
    while(p --)
    {
        int x, y, z; cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    for(int i = 1; i <= n; i ++) a[i] = a[i - 1] + d[i];
    int ans = 101;
    for(int i = 1; i <= n; i ++) ans = min(ans, a[i]);
    cout << ans << '\n';
    return 0;
}