    #include<bits/stdc++.h>
    using namespace std;

    const int N = 1e5 + 9;

    map<int, int> mp[N];

    int main()
    {
        int n, q; cin >> n >> q; 
        
        while(q --)
        {
            int op; cin >> op;
            if(op == 1)
            {
                int i, j, k; cin >> i >> j >> k;
                mp[i][j] = k;
            }else{
                int i, j; cin >> i >> j;
                cout << mp[i][j] << '\n';
            }
        }

        system("pause"); 
        return 0;
    }