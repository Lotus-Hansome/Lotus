#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
ll m[55];

int main()
{
    int n; cin >> n;
    
    for(int i = 1; i <= n; i ++) cin >> m[i];
    sort(m + 1, m + 1 + n);
    
    ll ans = 1;
    for(int i  = 1; i <= n; i ++)
    {
        ans = ans * (m[i] - i + 1) % MOD;
    }

    cout << ans << '\n';
    return 0;
}