#include<bits/stdc++.h>
using namespace std;

const int N = 20;
string s[N];
int cnt[N];
int len[N][N]; // j接i后面i能增加的长度
int ans;
vector<int> to[N];

int get_len(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        int l = 0;
        while(i + l < n && l < m && s1[i + l] == s2[l]) l ++;
        if(i + l == n) res = max(res, m - l);
    }

    return res;
}

void dfs(int x, int length)
{
    cnt[x] ++;

    for(const auto &y : to[x])
    {
        if(cnt[y] >= 2) continue;
        dfs(y, length + len[x][y]);
        cnt[y] --;
    }

    ans = max(ans, length);
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> s[i];

    char st; cin >> st;

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            len[i][j] = get_len(s[i], s[j]);
            if(len[i][j]) to[i].push_back(j);
            //cout << len[i][j] << ' ';
        }
    }

    for(int i = 1; i <= n; i ++)
    {
        if(s[i][0] == st)
        {
            dfs(i, s[i].size());
        }
    }

    cout << ans << '\n';

    system("pause");

    return 0;
}