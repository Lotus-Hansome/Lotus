#include<bits/stdc++.h>
using namespace std;

priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;


// 动态维护第k大的元素
void add(int x, int k)
{
    // mn非空时去比较，否则调用top()函数会触发未定义行为
    if(mn.size() && x >= mn.top()) mn.push(x);
    else mx.push(x);

    if(mn.size() < k)
    {
        mn.push(mx.top());
        mx.pop();
    }

    if(mn.size() > k)
    {
        mx.push(mn.top());
        mn.pop();
    }
}


int main()
{
    int n, w; cin >> n >> w;
    for(int i = 1; i <= n; i ++)
    {
        int x; cin >> x;
        int now = max(1, i * w / 100);
        add(x, now);
        cout << mn.top() << " ";
    }

    return 0;
}