/*
y-x=z-y,即x+z=2*y
所以x+z为偶数,所以x与z同奇偶
对于一个配对的x和z，总能找出一个y，所以我们并不关心y的值
然后又有colx=colz,所以所有同颜色且同奇偶的编号都可以满足三元组
然后在对公式化简，(x+z)*(numx+numz)
考虑x对结果的贡献（也可以考虑numx)，然后再进行累加
设和x配对的z有k个，那么x的贡献为x*k*num[x]+x∑(i=1~k)*numi
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int MOD = 1e4 + 7;

int num[N], col[N];
int cnt[N][2]; // cnt[i][j]存储颜色为i的格子的个数，j为0表示编号为偶数,为1表示奇数
int sum[N][2]; // sum[i][j]存储颜色为i的格子的编号和，j为0表示编号为偶数，为1表示奇数

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> num[i];
        num[i] %= MOD; //num[i]可能比MOD大, 不要忘记取模!!!
    }

    for(int i = 1; i <= n; i ++) cin >> col[i];

    for(int i = 1; i <= n; i ++)
    {
        cnt[col[i]][i & 1] = (cnt[col[i]][i & 1] + 1) % MOD;
        sum[col[i]][i & 1] = (sum[col[i]][i & 1] + num[i]) % MOD;
        // sum[col[i]][i & 1] = (sum[col[i]][i & 1] + i) % MOD;
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        // 能和i配对的数量
        int k = (cnt[col[i]][i & 1] - 1 + MOD) % MOD;
        // 与x配对的数的num和
        int s = (sum[col[i]][i & 1] - num[i] + MOD) % MOD;
        // int s = (sum[col[i]][i & 1] - i % MOD + MOD) % MOD;
        ans = (ans + k * i % MOD * num[i] % MOD + i * s % MOD) % MOD;
    }

    cout << ans << '\n';
    return 0;
}