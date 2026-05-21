/*
先让ans=n，然后再去判断什么时候ans可以减少
如果出现一对相同高度的建筑，且他们之间的建筑高度都不小于他们的高度
那么这对建筑只需要一张海报就可以满足需求，因此ans-1
也就是判断对于某个建筑，它左边第一个不大于他的建筑的高度是不是和他相等
可以用单调栈来实现
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int d[N], w[N];
int stk[N], top;

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> d[i] >> w[i];

    int ans = n;
    for(int i = 1; i <= n; i ++)
    {
        while(top && w[stk[top]] > w[i]) top --;
        if(w[stk[top]] == w[i]) ans --;
        stk[++ top] = i;    
    }

    cout << ans << '\n';
    return 0;
}