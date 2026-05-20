#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int x; cin >> x;
    unsigned int low = 0;
    for(int i = 1; i <= 16; i ++)
    {
        unsigned int bit = x >> 31 & 1;

        low = (low << 1) + bit;
        x <<= 1;
    }
    
    cout << x + low << '\n';
    return 0;
}