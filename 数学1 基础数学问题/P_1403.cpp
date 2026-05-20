#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 9;
int cnt[N];

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = i; j <= n; j += i)
        {
            cnt[j] ++;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++) ans += cnt[i];
    cout << ans << '\n';
    return 0;
}