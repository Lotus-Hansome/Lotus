#include<bits/stdc++.h>
using namespace std;

const int N = 35;
struct Node{
    int l, r;
}t[N];
string s1, s2;

int dfs1(string s)
{
    if(!s.size()) return -1;

    int rt, id;
    for(int i = 0; i < s2.size(); i ++)
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
    
    t[rt].l = dfs1(ls);
    t[rt].r = dfs1(rs);

    return rt;
}

void dfs2(int x)
{
    if(x == -1) return ;

    dfs2(t[x].l);
    dfs2(t[x].r);
    cout << s1[x];
}

int main()
{
    cin >> s1 >> s2;

    int rt = dfs1(s1);
    
    dfs2(rt);

    system("pause");
    return 0;
}