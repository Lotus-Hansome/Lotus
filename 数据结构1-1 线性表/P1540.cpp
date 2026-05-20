#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 9;

queue<int> q;
bool in[N];

int main()
{
    int m, n; cin >> m >> n;
    
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x; cin >> x;
        if(!in[x])
        {
            if(q.size() == m)
            {
                int y = q.front();
                q.pop();
                in[y] = false;
            }

            q.push(x);
            in[x] = true;
            ans ++;
        }
    }

    cout << ans << '\n';

    system("pause");
    return 0;
}