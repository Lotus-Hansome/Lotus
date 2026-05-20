#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int idx[N];
int stk[N], top;
bool in[N];

int main()
{
    int q; cin >> q;
    while(q --)
    {
        top = 0;
        memset(in, 0, sizeof(in));
        memset(idx, 0, sizeof(idx));
        int n; cin >> n;
        for(int i = 1; i <= n; i ++)
        {
            int x; cin >> x;
            idx[x] = i;
        }

        bool ok = true;
        int mx_idx = 0;
        for(int i = 1; i <= n; i ++)
        {
            int x; cin >> x;
            if(in[idx[x]])
            {
                if(stk[top] != idx[x]) ok = false;
                else{
                    top --;
                    in[idx[x]] = false;
                }
            }else{
                for(int j = mx_idx + 1; j < idx[x]; j ++)
                {
                    in[j] = true;
                    stk[++ top] = j;
                }
                mx_idx = max(mx_idx, idx[x]);
            }
        }

        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }

    system("pause");
    return 0;
}