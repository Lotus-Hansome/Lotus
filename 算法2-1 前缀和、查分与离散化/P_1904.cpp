#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e4 + 9;
int h[N];

int main()
{
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        // 折点总是成对出现，且横坐标相同
        // 左开右闭，统计该区间内每个横坐标对应的最大值
        // 因为c是出边，如果折点出现在c这条边时，奇数点在上方，输出横坐标，偶数点在下方，输出纵坐标(0)
        // 同时保证统计不出错
        // 比如 3 10 4
        //      5 10 6
        // 4和5之间是有缝隙的，不联通，写成闭区间会将他们联通，统计错误
        for(int i = a; i < c; i ++) 
        {
            h[i] = max(h[i], b);
        }
    }

    for(int i = 0; i < 1e4; i ++)
    {
        if(h[i] != h[i + 1]) cout << i + 1 << " " << h[i + 1] << " ";  
    }

    return 0;
}