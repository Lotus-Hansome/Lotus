#include<bits/stdc++.h>
using namespace std;

const int N = 15;
string A, B;
string a[N], b[N];
int n;

unordered_map<string, bool> mp;
struct Node{
    string s;
    int step;
};
queue<Node> q;

void bfs()
{
    q.push({A, 0});
    
    while(q.size())
    {
        string s = q.front().s;
        int step = q.front().step;
        q.pop();
    
        if(s == B)
        {
            cout << step << '\n';
            return ;
        }

        if(step >= 10) break;
        
        if(mp[s]) continue;
        mp[s] = true;
        
        for(int i = 1; i <= n; i ++)
        {
            int pos = 0;
            while((pos = s.find(a[i], pos)) != -1)
            {
                
                string tmp = s;
                tmp.replace(pos, a[i].size(), b[i]);
                
                if(!mp[tmp]) q.push({tmp, step + 1});
                pos ++;
            }
        }
    }

    cout << "NO ANSWER!\n";
}

int main()
{
    cin >> A >> B;
    n = 1;
    while(cin >> a[n] >> b[n]) n ++;
    n --;

    bfs();

    return 0;
}