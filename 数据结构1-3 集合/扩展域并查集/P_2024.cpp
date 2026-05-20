#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;

// 1~n为x的同类域, n+1~2n为x的捕食域(被x吃), 2n+1~3n为x的天敌域(吃x)
// 由于A吃B, B吃C, C吃A，所以这三种关系都满足传递性，可以用扩展与并查集来做
int pre[N * 3];

int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void Merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if(rx == ry) return ;
    pre[rx] = ry;
}

int main()
{
    int n, k; cin >> n >> k;
    for(int i = 1; i <= 3 * n; i ++) pre[i] = i;

    int ans = 0;
    for(int i = 1; i <= k; i ++)
    {
        int op, x, y; cin >> op >> x >> y;
        if(x > n || y > n) ans ++; // x或y比N大，是假话
        else if(op == 1)
        {
            // 如果y吃x或者x吃y，就说明x和y是同类这句话为假话
            if(root(x) == root(y + n) || root(x) == root(y + 2 * n)) ans ++;
            else // 否则x和y是同类为真话
            {
                Merge(x, y);
                Merge(x + n, y + n);
                Merge(x + 2 * n, y + 2 * n);
            }
        }
        else
        {
            // 如果x和y是同类，或者说y吃x，那么就说明x吃y是假话
            if(root(x) == root(y) || root(x) == root(y + n)) ans ++;
            else // 否则x吃y是真话
            {
                Merge(x + n, y); // x吃y, y和x的捕食域属于一个集合
                Merge(x, y + 2 * n); // x吃y, x和y的天敌域属于同一个集合
                Merge(y + n, x + 2 * n); // x吃y,y吃y+n,y+n吃x, y+n和x属于同一个集合
            }
        }
    }

    cout << ans << '\n';
    return 0;
}