#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
int a[N];

int Gcd(int m, int n)
{
    return n == 0 ? m : Gcd(n, m % n);
}

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    a[2] /= Gcd(a[1], a[2]);
    for(int i = 3; i <= n; i ++) a[2] /= Gcd(a[2], a[i]);
    if(a[2] == 1) puts("Yes");
    else puts("No");
}

int main()
{
    int t; cin >> t;
    while(t --)
    {
        solve();
    }

    return 0;
}