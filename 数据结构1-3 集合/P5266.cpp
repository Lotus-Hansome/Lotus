#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main()
{
    int q; cin >> q;
    while(q --)
    {
        int op; cin >> op;
        string name; 
        if(op != 4) cin >> name;
        if(op == 1)
        {
            int score; 
            cin >> score;
            mp[name] = score;
            cout << "OK\n";
        }
        else if(op == 2)
        {
            if(!mp.count(name)) cout << "Not found\n";
            else cout << mp[name] << '\n';
        }
        else if(op == 3)
        {
            if(!mp.count(name)) cout << "Not found\n";
            else{
                cout << "Deleted successfully\n";
                mp.erase(name);
            }
        }
        else cout << mp.size() << '\n';
    }

    system("pause");
    return 0;
}