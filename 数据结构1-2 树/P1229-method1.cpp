#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;

struct Node{
    bool ls, rs;
}tree[N];

string s1, s2;

// 根据先序序列和后序序列求中序序列的总数
// 由于是二叉树，所以序列总数取决于只有一个孩子的节点的个数
// 因为对于这种节点，他的孩子可能是左孩子，也可能是右孩子
// 假设有n中这样的节点，那么答案就是2^n
// 那怎么求解只有一个孩子的节点的个数呢
// 可以将他的后序序列翻转过来，那么序列满足的关系就是根右左
// 而先序序列满足根左右的关系
// 所以对于先序序列中的两个节点i和他后面的一个节点j
// 如果在后序序列中也满足这种先后关系，那么就说明j是i的孩子
// 否则就去先序序列前面继续找到满足这种关系的节点k，j是k的孩子
int main()
{
    cin >> s1 >> s2;
    reverse(s2.begin(), s2.end());
    for(int i = 1; i < s1.size(); i ++)
    {
        int j = i - 1;
        while(s2.find(s1[j]) > s2.find(s1[i])) j --;
        if(tree[j].ls) tree[j].rs = true;
        else tree[j].ls = true;
    }

    int ans = 0;
    for(int i = 0; i < s1.size(); i ++)
    {
        if(tree[i].ls && !tree[i].rs) ans ++;
    }

    cout << (1LL << ans) << '\n';
    
    system("pause");
    return 0;
}