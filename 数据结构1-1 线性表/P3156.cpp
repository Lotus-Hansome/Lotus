#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;
int a[N];

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    while(m --)
    {
        int idx; cin >> idx;
        cout << a[idx] << '\n';
    }

    system("pause");
    return 0;
}