#include<bits/stdc++.h>
using namespace std;

priority_queue<int> mx_pq;
priority_queue<int, vector<int>, greater<int>> mn_pq;

void add(int x)
{
    if(mn_pq.size() && x > mn_pq.top()) mn_pq.push(x);
    else mx_pq.push(x);
    if(mn_pq.size() > mx_pq.size())
    {
        int y = mn_pq.top();
        mn_pq.pop();
        mx_pq.push(y);
    }

    if(mx_pq.size() - mn_pq.size() > 1)
    {
        int y = mx_pq.top();
        mx_pq.pop();
        mn_pq.push(y);
    }
}

int getmid()
{
    return mx_pq.top();
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int x; cin >> x;
        add(x);
    }

    int m; cin >> m;
    for(int i = 1; i <= m; i ++)
    {
        string op; cin >> op;
        if(op == "add")
        {
            int x; cin >> x;
            add(x);
        }
        else cout << getmid() << '\n';
    }

    return 0;
}