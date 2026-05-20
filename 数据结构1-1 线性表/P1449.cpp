#include<bits/stdc++.h>
using namespace std;

stack<int> stk;

void suanshu(char op)
{
    int b = stk.top(); stk.pop();
    int a = stk.top(); stk.pop();
    int res;
    if(op == '+') res = a + b;
    else if(op == '-') res = a - b;
    else if(op == '*') res = a * b;
    else res = a / b;

    stk.push(res);
}

int main()
{
    string s; cin >> s;

    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] == '@') break;
        if('0' <= s[i] && s[i] <= '9')
        {
            int x = 0;
            while(s[i] != '.' && i + 1 < s.size())
            {
                x = x * 10 + s[i] - '0';
                i ++;
            }
            stk.push(x);
        }
        else suanshu(s[i]);
    }

    cout << stk.top() << '\n';
    
    system("pause");
    return 0;
}