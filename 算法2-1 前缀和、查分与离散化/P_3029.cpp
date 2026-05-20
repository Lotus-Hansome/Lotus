/*
本题可以使用双指针来做，要找出长度最小的区间[l,r]，使得该区间包含所有种类的牛
由于种类最多只有5e4种，而值域又很大，所以需要离散化
对于左端点l，如果能找到一个最小的右端点r，使得该区间满足条件
那么比l小的左端点一定都满足条件，而比l大的左端点它对应的最小右端点一定不比r小
所以满足单调性，可以使用双指针来求解满足条件的最小区间
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;
struct Cow{
    int x, id;

    bool operator<(const Cow &u)const{
        return x < u.x;
    }
}cow[N];

vector<int> L;
int cnt[N];
int m;

void discrete(int n)
{
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    m = L.size();
    for(int i = 1; i <= n; i ++)
    {
        cow[i].id = lower_bound(L.begin(), L.end(), cow[i].id) - L.begin() + 1;
    }
}
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> cow[i].x >> cow[i].id;
        L.push_back(cow[i].id);
    }

    sort(cow + 1, cow + 1 + n);

    discrete(n);

    int siz = 0, ans = INT_MAX;
    for(int l = 1, r = 0; l <= n; l ++)
    {
        while((siz < m && r < n) || r == 0)
        {
            r ++;
            if(!cnt[cow[r].id]) siz ++;
            cnt[cow[r].id] ++;
        }
        
        if(siz == m) ans = min(ans, cow[r].x - cow[l].x);
        if(-- cnt[cow[l].id] == 0) siz --;
    }

    cout << ans << '\n';
    return 0;
}