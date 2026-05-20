#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N], b[N];
int cnt;

int Gcd(int m, int n)
{
    return (n == 0 ? m : Gcd(n, m % n));
}

int Lcm(int m, int n)
{
    return m * n / Gcd(m, n);
}

int main()
{
    string s; cin >> s;
    int t = 1;
    int i = 0;
    while(i < s.size())
    {
        int f = 1;
        while(s[i] < '0' || s[i] > '9')
        {
            if(s[i] == '-') f = -1;
            i ++;
        }

        if(t) cnt ++;
        while(i < s.size() && '0' <= s[i] && s[i] <= '9')
        {
            if(t) a[cnt] = a[cnt] * 10 + s[i] - '0';
            else b[cnt] = b[cnt] * 10 + s[i] - '0';
            i ++;
        }
        if(t) a[cnt] *= f;
        else b[cnt] *= f;
        t ^= 1;
    }

    int x = a[1], y = b[1];
    for(int i = 2; i <= cnt; i ++)
    {
        bool flag = true;
        int _x = a[i], _y = b[i];
        if((_x < 0) ^ (_y < 0)) flag = false;
        _x = abs(_x), _y = abs(_y);
        int lcm = Lcm(y, _y);
        x *= lcm / y;
        _x *= lcm / _y;
        
        if(flag) x += _x;
        else x -= _x;

        y = lcm;
        int g = Gcd(x, y);
        x /= g;
        y /= g;
    }

    int g = Gcd(x, y);
    x /= g;
    y /= g;

    char f = '+';
    if((x < 0) ^ (y < 0)) f = '-';
    x = abs(x), y = abs(y);
    if(f == '-') cout << f;
    cout << x;
    if(y > 1) cout << '/' << y;
    return 0;
}