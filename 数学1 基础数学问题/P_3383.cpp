#include<bits/stdc++.h>
using namespace std;

const int N = 1e8 + 9;
bool vis[N];
vector<int> primes;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vis[0] = vis[1] = true;
    int n; cin >> n;
    for(int i = 2; i <= n; i ++)
    {
        if(!vis[i]) primes.push_back(i);
        for(int j = 0; 1ll * i * primes[j] <= n; j ++)
        {
            vis[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }

    int q; cin >> q;
    while(q --)
    {
        int k; cin >> k;
        cout << primes[k - 1] << '\n';
    }

    return 0;
}