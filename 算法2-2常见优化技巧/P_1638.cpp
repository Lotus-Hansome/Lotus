#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int a[N];
int cnt[N];

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    int siz = 0, cost = INT_MAX;
    int x, y;
    for(int l = 1, r = 0; l <= n; l ++)
    {
        while((siz < m && r < n) || (r == 0))
        {
            r ++;
            if(!cnt[a[r]]) siz ++;
            cnt[a[r]] ++;
        }

        if(siz == m)
        {
            if(r - l + 1 < cost)
            {
                cost = r - l + 1;
                x = l;
                y = r;
            }
        }
        
        if(-- cnt[a[l]] == 0) siz --;
    }

    cout << x << " " << y << '\n';
    return 0;
}