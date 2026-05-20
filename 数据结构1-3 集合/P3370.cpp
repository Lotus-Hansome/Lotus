#include<bits/stdc++.h>
using namespace std;

using  ull = unsigned long long;

const int N = 1e4 + 9;

int a[N];
ull base = 599;

int main()
{
    int n; cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        string s; cin >> s;
        ull hash = 0;
        for(int j = 0; j < s.size(); j ++) hash = hash * base + int(s[j]);
        a[i] = hash;
    }

    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++) if(a[i] != a[i + 1]) ans ++;
    
    cout << ans << '\n';

    system("pause");
    return 0;
}