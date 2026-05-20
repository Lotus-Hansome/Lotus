#include<bits/stdc++.h>
using namespace std;

char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;

    int x = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        if(isdigit(s[i])) x = x * n + s[i] - '0';
        else x = x * n + s[i] - 'A' + 10;
    }
    
    string ans;
    while(x)
    {
        ans += ch[x % m];
        x /= m;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}