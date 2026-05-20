#include<bits/stdc++.h>
using namespace std;

// 当父节点有两个孩子时，先序顺序是 父 -> 左子树 -> 右子树，后序顺序是 左子树 -> 右子树 -> 父
// 此时，先序中 “父” 后面是左子树的根，后序中 “父” 前面是右子树的根，两者不相等
// 当父节点只有一个孩子时，先序顺序是 父 -> 子，后序顺序是 子 -> 父
// 此时，先序中 “父” 后面是 “子”，后序中 “父” 前面也是 “子”，完美匹配 str1[i+1]==str2[j-1]，触发统计

int main()
{
    string s1, s2; cin >> s1 >> s2;

    int ans = 0;
    for(int i = 0; i < s1.size(); i ++)
    {
        for(int j = 1; j < s2.size(); j ++)
        {
            if(s1[i] == s2[j] && s1[i + 1] == s2[j - 1]) ans ++;
        }
    }

    cout << (1LL << ans) << '\n';

    system("pause");
    return 0;
}