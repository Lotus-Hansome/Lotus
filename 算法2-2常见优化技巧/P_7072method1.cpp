#include<bits/stdc++.h>
using namespace std;

const int N = 609;

int cnt[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, w; cin >> n >> w;
    for(int i = 1; i <= n; i ++)
    {
        int x; cin >> x;
        cnt[x] ++;
        int rk = 0;
        for(int j = 600; j >= 0; j --)
        {   
            rk += cnt[j];
            if(rk >= max(1, w * i / 100))
            {
                cout << j << " ";
                break;
            }
        }
    }

    return 0;
}