#include<bits/stdc++.h>
using namespace std;

string s = "0123456789ABCDEFGHIJ";

int main()
{
    int n, r; cin >> n >> r;
    cout << n << "=";
    string ans;
    while(n)
    {
        int x = n % r;
        if(x < 0)
        {
            n = (n + r) / r; // 余数减r，让被除数加r
            x -= r; // 让余数为正
        }else {
            n /= r;
        }

        ans = s[x] + ans;
    }

    cout << ans << "(base" << r << ")";
    return 0;
}