#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 9;
int a[N];
set<int> st;

int main()
{
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        if(i == 1)
        {
            ans += a[i];
            st.insert(a[i]);
            continue;
        }
        
        auto it = st.lower_bound(a[i]);
        int mn = 1e9 + 7;
        if(it != st.end()) mn = min(mn, abs(*it - a[i]));
        if(it != st.begin()) mn = min(mn, abs(*(-- it) - a[i]));

        ans += mn;
        st.insert(a[i]);
    }

    cout << ans << '\n';
    system("pause");
    return 0;
}