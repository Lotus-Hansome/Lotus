#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

double a[N], b[N];
int n;

bool cmp(double x, double y) { return x > y; }

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    
    double ans = 0, suma = 0, sumb = 0;
    int cnta = 0, cntb = 0;

    while(cnta + cntb < 2 * n)
    {
        if(suma < sumb)
        {
            if(cnta < n) suma += a[++ cnta];
            else break;
        }
        else {
            if(cntb < n) sumb += b[++ cntb];
            else break;
        }
        ans = max(ans, min(suma, sumb) - (cnta + cntb));
    }

    cout << fixed << setprecision(4);
    cout << ans << '\n';    
    return 0;
}