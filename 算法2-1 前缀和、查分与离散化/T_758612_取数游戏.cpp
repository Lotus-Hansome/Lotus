#include <iostream>
#include <vector>
#include <unordered_set>
#include<cstring>
using namespace std;

int sg[25];

int mex(unordered_set<int> st)
{
    int res = 0;
    while(st.count(res)) res ++;
    return res;
}

int compute_sg(int x, int idx)
{
    if(x == 0) return 0;
    if(sg[x] != -1) return sg[x];

    unordered_set<int> st;  
    if(x >= 1) st.insert(compute_sg(x - 1, idx));
    if(x >= 2) st.insert(compute_sg(x - 2, idx));
    if(x >= idx) st.insert(compute_sg(x - idx, idx));

    return mex(st);
}

void print(int idx)
{
    memset(sg, -1, sizeof sg);
    cout << idx << ":\n";
    for(int i = 0; i <= 20; i ++)
    {
        cout << "SG" << i << compute_sg(i, idx) << " ";
    }
    cout << '\n';
}

int main()
{
    for(int i = 1; i <= 6; i ++)
    {
        print(i);
    }

    return 0;
}