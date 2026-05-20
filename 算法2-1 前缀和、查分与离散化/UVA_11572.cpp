#include<bits/stdc++.h>
using namespace std;

unordered_map<int, bool> mp;

void solve()
{
    mp.clear();
    int n; cin >> n;
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i ++) 
    {
        int x; cin >> x;
        cnt ++;
        if(mp[x] || i == n)
        {
            ans = max(ans, cnt);
            cnt = 0;
            mp.clear();
        }
        mp[x] = true;
    }

    cout << ans << '\n';
}

int main()
{
    int _; cin >> _;

    while(_ --)
    {
        solve();
    }

}