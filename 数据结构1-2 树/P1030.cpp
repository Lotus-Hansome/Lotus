#include<bits/stdc++.h>
using namespace std;

const int N = 15;
struct Node{
    int lc, rc;
}tree[N];

string s1, s2;

int  dfs1(string s)
{
    if(!s.size()) return -1;

    int rt, id;
    for(int i = s2.size() - 1; i >= 0; i --)
    {
        if(s.find(s2[i]) != string::npos)
        {
            rt = s1.find(s2[i]);
            id = s.find(s2[i]);
            break;
        }
    }

    string ls, rs;
    for(int i = 0; i < s.size(); i ++)
    {
        if(i < id) ls += s[i];
        if(i > id) rs += s[i];
    }

    tree[rt].lc = dfs1(ls);
    tree[rt].rc = dfs1(rs);
    return rt;
}

void dfs2(int x)
{
    if(x == -1) return ;

    cout << s1[x];
    dfs2(tree[x].lc);
    dfs2(tree[x].rc);
}

int main()
{
    cin >> s1 >> s2;

    int rt = dfs1(s1);

    dfs2(rt);

    system("pause");
    return 0;
}