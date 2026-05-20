#include<bits/stdc++.h>
using namespace std;

set<int> st;

int main()
{
    int m; cin >> m;
    while(m --)
    {
        int op, x; cin >> op >> x;
        if(op == 1)
        {
            if(st.find(x) != st.end()) cout << "Already Exist\n";
            else st.insert(x);
        }else {
            if(!st.size()) cout << "Empty\n";
            else {
                auto it = st.upper_bound(x);
                int res = INT_MAX;
                if(it != st.end()) res = *it;
                if(it != st.begin())
                {
                    -- it;
                    if(abs(*it - x) <= abs(res - x)) res = *it;
                }
                cout << res << '\n';
                st.erase(res);
            }
        }
    }

    system("pause");
    return 0;
}