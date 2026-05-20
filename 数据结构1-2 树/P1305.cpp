#include<bits/stdc++.h>
using namespace std;

const int N = 35;
struct Node{
    char ls, rs, val;
}tree[N];

map<char, int> mp;

void dfs(int x)
{
    if(x == 0) return ;
    int ls = mp[tree[x].ls], rs = mp[tree[x].rs];

    cout << tree[x].val;
    dfs(ls);
    dfs(rs);
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> tree[i].val >> tree[i].ls >> tree[i].rs;
        mp[tree[i].val] = i;
    }

    dfs(1);

    system("pause");
    return 0;
}