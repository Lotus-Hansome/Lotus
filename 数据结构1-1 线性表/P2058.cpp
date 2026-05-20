#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int t[N], k[N];
vector<int> x[N];
int cnt[N];

int main()
{
    int n; cin >> n;

    int mn_idx = 0, ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        cin >> t[i] >> k[i];
        for(int j = 1; j <= k[i]; j ++)
        {
            int a; cin >> a;
            cnt[a] ++;
            if(cnt[a] == 1) ans ++;
            x[i].push_back(a);
        }

        while(t[i] - t[mn_idx] >= 86400)
        {
            for(const auto a : x[mn_idx])
            {
                cnt[a] --;
                if(cnt[a] == 0) ans --;
            }
            mn_idx ++;
        }
        
        cout << ans << '\n';
    }

    system("pause");
    return 0;
}