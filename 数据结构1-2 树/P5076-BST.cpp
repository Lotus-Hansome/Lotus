#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
const int INF = 0x7fffffff;

int tol;
struct Node{
    // val为当前节点的值，ls为左儿子，rs为右儿子，siz为以当前节点为根的子树大小
    int val, ls, rs, cnt, siz;
}tree[N];

// x为当前节点编号，v为需要插入的值
// 往BST树中添加元素v
inline void add(int x, int v)
{
    // v在x子树中，tree[x].siz ++
    tree[x].siz ++;

    // 如果当前节点的值=v（要插入的值）
    // 说明之前就存在v这个值，也就是有重复的数，tree[x].val ++
    if(tree[x].val == v) 
    {
        tree[x].cnt ++;
        return ;
    }

    // 如果当前节点的值>v，说明v在x的左子树里
    if(tree[x].val > v) 
    {
        // 左子树不为空，那么在左子树中插入v
        if(tree[x].ls != 0) add(tree[x].ls, v);
        else // 否则就找到了v的位子，v就是x的左孩子
        {
            tol ++;
            tree[tol].val = v;
            tree[tol].siz = tree[tol].cnt = 1;
            tree[x].ls = tol;
        }
    }
    else // v在x的左子树里
    {
        // 左子树不为空，那么在左子树中插入v
        if(tree[x].rs != 0) add(tree[x].rs, v);
        else // 否则就找到了v的位子，v就是x的右孩子
        { 
            tol ++;
            tree[tol].val = v;
            tree[tol].siz = tree[tol].cnt = 1;
            tree[x].rs = tol;
        }
    }
}

/*
inline void del(int x, int v) 与上述add同理
*/

// 找到比v小的最大的数，v是要查找的值，ans是目前查找到的比v小的最大值
int queryfr(int x, int v, int ans)
{
    // 如果当前节点值>=v
    if(tree[x].val >= v)
    {
        // 左子树为空，由于右子树里的数都大于当前数，所以没有再比ans大且小于v的数了，直接返回ans即可
        if(tree[x].ls == 0) return ans;
        // 否则继续去左子树里查找，此时无需更新ans，因为tree[x].val>=v，而我们要找的数要比v小
        else return queryfr(tree[x].ls, v, ans);
    }
    else // 如果当前节点值<v
    {
        // 右子树为空，说明没有比tree[x].val更大的数了，注意此时tree[x].val>ans,否则不会递归到x子树
        // 所以应该返回tree[x].val
        if(tree[x].rs == 0) return tree[x].val;

        // 否则去右子树查找，注意此时需要更新ans，因为ans<tree[x].val且tree[x].val<v
        // 判断tree[x].cnt != 0的原因是如果有删除操作的话，当前节点可能被删除了
        // 只不过这题没有删除操作，所以不用判断也可以
        if(tree[x].cnt != 0) return queryfr(tree[x].rs, v, tree[x].val);
        else return queryfr(tree[x].rs, v, ans);
    }
}

// 找到比v大的最小的数，与查找前驱原理相似，反过来即可
int queryne(int x, int v, int ans)
{
    if(tree[x].val <= v)
    {
        if(tree[x].rs == 0) return ans;
        return queryne(tree[x].rs, v, ans);
    }
    else
    {
        if(tree[x].ls == 0) return tree[x].val;
        if(tree[x].cnt != 0) return queryne(tree[x].ls, v, tree[x].val);
        else return queryne(tree[x].ls, v, ans);
    }
}

// 根据值找排名
// 查询比v小的数的个数，x的排名为集合中小于x的数的个数+1
int queryval(int x, int v)
{
    if(x == 0) return 0; // 递归终止条件，当前子树为空
   
    // 如果当前节点值==v，则小于v的数的个数就是他的左子树的大小
    if(tree[x].val == v) return tree[tree[x].ls].siz;
    
    // 如果当前节点值>v，说明要去左子树查找
    if(tree[x].val > v) return queryval(tree[x].ls, v);

    // 如果当前节点值<v,说明当前节点及他的左子树的值都小于v
    // 再去右子树查找有多少数小于v
    return queryval(tree[x].rs, v) + tree[tree[x].ls].siz + tree[x].cnt;
}

// 根据排名找值
// 查询排名为rk的那个数
int queryrk(int x, int rk)
{
    if(x == 0) return INF;// 不存在排名为rk的数

    // 左子树大小>=rk，说明排名为rk的数在左子树中
    if(tree[tree[x].ls].siz >= rk) return queryrk(tree[x].ls, rk);

    // 左子树大小<rk，同时左子树大小加上当前节点x的个数>=rk，说明x就是要找的节点，返回tree[x].val
    if(tree[tree[x].ls].siz + tree[x].cnt >= rk) return tree[x].val;

    // 否则说明排名为rk的数在右子树中，继续去右子树查找
    return queryrk(tree[x].rs, rk - tree[tree[x].ls].siz - tree[x].cnt);
}

int main()
{
    int q; cin >> q;
    while(q --)
    {
        int op, x; cin >> op >> x;
        if(op == 1) cout << queryval(1, x) + 1 << '\n';
        else if(op == 2) cout << queryrk(1, x) << '\n';
        else if(op == 3) cout << queryfr(1, x, -INF) << '\n';
        else if(op == 4) cout << queryne(1, x, INF) << '\n';
        else if(op == 5)
        {
            if(tol == 0)
            {
                tol ++;
                tree[tol].cnt = 1;
                tree[tol].siz = 1;
                tree[tol].val = x;
            }else add(1, x);
        }
    }

    system("pause");
    return 0;
}