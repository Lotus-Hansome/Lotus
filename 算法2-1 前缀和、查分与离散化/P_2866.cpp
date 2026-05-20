#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 8e4 + 9;

int a[N];
int stk[N], top;

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    
    ll ans = 0;
    for(int i = n; i >= 1; i --)
    {
        // 注意要求的是右边第一个不小于(不是小于)a[i]的数
        while(top && a[stk[top]] < a[i]) top --;
        if(top == 0) ans += n - i;
        else ans += stk[top] - i - 1;
        stk[++ top] = i; 
    }

    cout << ans << '\n';
    return 0;
}