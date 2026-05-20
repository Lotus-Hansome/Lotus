#include<bits/stdc++.h>
using namespace std;

const int N = 27;

unordered_map<string, int> mp;

int n = 26;
int ans = 0;

void dfs(int u, int dep, int len, string s)
{
    if(dep == len)
    {
        ans ++;
        mp[s] = ans;
        return ;
    }
    for(int i = u + 1; i <= n; i ++) dfs(i, dep + 1, len, s + char(i + 'a' - 1));
}

int main()
{
    string s; cin >> s;
    for(int len = 1; len <= 6; len ++)
    {
        dfs(0, 0, len, "");
    }

    cout << mp[s] << '\n';

	return 0; 
}