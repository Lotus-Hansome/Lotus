#include<bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int a; cin >> a;
        mp[a] ++;
    }

    int q; cin >> q;
    while(q --)
    {
        int m; cin >> m;
        cout << mp[m] << '\n';
    }

    system("pause");
    return 0;
}