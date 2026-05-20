#include<bits/stdc++.h>
using namespace std;

map<string, string> mp;

int main()
{
    string s; cin >> s;
    while(s != "$")
    {
        if(s[0] == '#')
        {
            s.erase(0, 1);
            string t; cin >> t;
            while(t[0] == '+')
            {
                t.erase(0, 1);
                mp[t] = s;
                cin >> t;
            }
            s = t;
            continue;
        }
        else if(s[0] == '?')
        {
            s.erase(0, 1);
            string ansc = s;
            while(mp.count(ansc) != 0) ansc = mp[ansc];
            cout << s << " " << ansc << '\n';
        }

        cin >> s;
    }
    
    system("pause");
    return 0;
}