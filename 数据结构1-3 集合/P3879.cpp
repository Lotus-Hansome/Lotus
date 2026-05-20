#include<bits/stdc++.h>
using namespace std;

map<string, set<int>> mp;

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        int L; cin >> L;
        for(int j = 1; j <= L; j  ++)
        {
            string word; cin >> word;
            mp[word].insert(i);
        }
    }

    int m; cin >> m;
    for(int i = 1; i <= m; i ++)
    {
        string s; cin >> s;
        if(!mp.count(s)) cout << " \n";
        else{
            for(const auto &id : mp[s])
            {
                cout << id << " ";
            }
            cout << '\n';
        }
    }

    system("pause");
    return 0;
}