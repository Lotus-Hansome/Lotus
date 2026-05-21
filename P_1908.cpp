#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 9;
int a[N], b[N];

ll Merge_sort(int a[], int l, int r)
{
    if(l >= r) return 0;
    int mid = (l + r) / 2;
    ll res = 0;
    res += Merge_sort(a, l, mid);
    res += Merge_sort(a, mid + 1, r);

    int pl = l, pr = mid + 1, pb = l;
    while(pl <= mid || pr <= r)
    {
        if(pl > mid) b[pb ++] = a[pr ++];
        else if(pr > r) b[pb ++] = a[pl ++];
        else {
            if(a[pl] <= a[pr]) {
                b[pb ++] = a[pl ++];
            } else {
                res += mid - pl + 1;
                b[pb ++] = a[pr ++];
            }
        }
    }

    for(int i = l; i <= r; i ++) a[i] = b[i];
    return res;
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    cout << Merge_sort(a, 1, n) << '\n';
    return 0;
}