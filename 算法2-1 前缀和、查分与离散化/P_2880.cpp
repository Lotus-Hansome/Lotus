#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;

int h[N], st_mn[N][25], st_mx[N][25];
int n;

int getmx(int l, int r)
{
    int k = log2(r - l + 1);
    return max(st_mx[l][k], st_mx[r - (1 << k) + 1][k]); 
}

int getmn(int l, int r)
{
    int k = log2(r - l + 1);
    return min(st_mn[l][k], st_mn[r - (1 << k) + 1][k]);
}

int query(int l, int r)
{
    return getmx(l, r) - getmn(l, r);
}

int main()
{
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i ++) 
    {
        cin >> h[i];
        st_mx[i][0] = h[i];
        st_mn[i][0] = h[i];
    }

    for(int j = 1; j <= 20; j ++)
    {
        for(int i = 1; i <= n; i ++)
        {
            if((i + (1 << j)) - 1 <= n)
            {
                st_mx[i][j] = max(st_mx[i][j - 1], st_mx[i + (1 << (j - 1))][j - 1]);
                st_mn[i][j] = min(st_mn[i][j - 1], st_mn[i + (1 << (j - 1))][j - 1]);
            } 
        }
    }

    while(q --)
    {
        int a, b; cin >> a >> b;
        cout << query(a, b) << '\n';
    }

    return 0;
}