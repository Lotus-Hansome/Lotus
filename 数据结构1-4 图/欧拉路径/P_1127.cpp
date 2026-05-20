/*
要求每个单词在词链中只出现一次
由此想到欧拉路径中每条边都只能走一次的特点
由于词链中每个相邻单词的首尾字母都相同
所以对于每个单词，可以以它的首字母为出发点，末尾字母为目的地，建一条边权为该单词的边
由于'.'在计算字典序时也要算进去，而'.'的字典序比小写字母的字典序要小
所以要得到最小的字典序，只需将每个点所连的边的边权升序排序即可
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;
string s[N];

struct Node{
    int x;
    string w;

    bool operator<(const Node &u)const{
        return w < u.w;
    }
};
vector<Node> g[30];

int cur[N];
int outdeg[N], indeg[N];
string path[N];
int cntp;

int findst()
{
    int st = -1, ed = -1;
    for(int i = 1; i <= 26; i ++)
    {
        int v = outdeg[i] - indeg[i];
        if(v < -1 || v > 1 || (v == 1 && st != -1) || (v == -1 && ed != -1)) return -1;
        if(v == 1) st = i;
        if(v == -1) ed = i;
    }

    if((st == -1) ^ (ed == -1)) return -1;
    if(st != -1) return st;

    for(int i = 1; i <= 26; i ++) if(outdeg[i] > 0) return i;
}

void euler(int x, string p)
{
    for(int i = cur[x]; i < g[x].size(); i = cur[x])
    {
        cur[x] ++;
        int y = g[x][i].x;
        string w = g[x][i].w;
        euler(y, w);
    }

    if(p.size())path[++ cntp] = p;
}

int main()
{
    int n; cin >> n;
    int m = 0;
    for(int i = 1; i <= n; i ++)
    {
        string s; cin >> s;
        int x = s[0] - 'a' + 1, y = s.back() - 'a' + 1;
        g[x].push_back({y, s});
        m ++;
        indeg[y] ++;
        outdeg[x] ++;
    }

    for(int i = 1; i <= 26; i ++) sort(g[i].begin(), g[i].end());

    int st = findst();
    if(st == -1)
    {
        cout << "***\n";
        return 0;
    }

    euler(st, "");

    if(cntp != m) cout << "***\n";
    else {
        for(int i = cntp; i >= 1; i --)
        {
            cout << path[i];
            if(i != 1) cout << ".";
        }
    }

    return 0;
}