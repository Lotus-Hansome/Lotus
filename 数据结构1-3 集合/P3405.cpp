#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;

// 奶牛找城市只看前两位字母，对于城市A，所在州为B
// 对于城市C，所在州为D，假设城市A和城市C可以配对
// 那么A的前两位字母就等于D，C的前两位字母就等于B
// 假设A=MIAMI B=FL
//     C=FLINT D=MI
// 只保留A的前两位MI，C的前两位FL
// _A=MI B=FL
// _C=FL D=MI
// 可以发现_A+B==_C+D
// 将_A+B看成一个整体，然后擦找B+_A的个数就是可以和他城市配对的数量
// 为了防止重复统计，对于每个城市，只统计前面可以和他配对的数量

int main()
{
    int n; cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        string s1, s2; cin >> s1 >> s2;
        s1 = s1.substr(0, 2);

        if(s1 == s2) continue; // 如果s1==s2，则无需查找，因为满足条件的城市跟他来自同一个州
        
        ans += mp[s2 + s1];
        mp[s1 + s2] ++;
    }

    cout << ans << '\n';
    return 0;
}