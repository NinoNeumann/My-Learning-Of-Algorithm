//
// Created by Nino Neumann on 2023/3/1.
//

// 按的顺序是任意的 无关的
// 每个格子最多按一次
// 1 枚举第一行的操作 2^5 种
// 2 第一行操作完成那么第二行必定按第一行暗的那个各自的下一个 ==> 第二行的状态 操作是唯一确定的 ==> 以此类推第三行也是固定的。。。
// 3 每一行的操作都被其上一行唯一确定
// 4 最后判断最后一行是否是全亮
// 这题自己没好好做 mark一下
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 6;
int dx[N] = {-1, 0, 1, 0, 0}, dy[N] = {0, 1, 0, -1, 0};
char g[N][N], backup[N][N];


void turn (int x, int y)
{
    for (int i = 0; i < 5; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        g[a][b] ^= 1;   //异或，不同的时候就变成相反的数
    }

}


int main()
{
    int n;
    scanf("%d", &n);
    while(n -- )
    {
        // 按行输入，把每一行当成一个字符串
        for (int i = 0; i < 5; i ++ ) cin >> g[i];

        int res = 10;

        for (int op = 0; op < 32; op ++ )
        {
            memcpy(backup, g, sizeof g);
            int step = 0;
            for (int i = 0; i < 5; i ++ )
                if (op >> i & 1)  // 数字2 对应了 00010 表示第2个位置的按一下
                    // 00010 >> 1 & 1  是1 所以turn(0, 1) 就是第一行第二个位置
                {                 // 数字3 对应了00011 表示第1 和第2个位置的按一下
                    step ++ ;
                    turn (0, i);;
                }

            // 然后通过第一行按完之后的状态，按234行
            for (int i =0; i < 4; i ++ )
                for (int j = 0; j < 5;j ++ )
                    if (g[i][j] == '0')
                    {
                        step ++;
                        turn (i + 1, j);  // 如果这个位置是灭的，就按下一行对应的位置
                    }

            bool dark = false;
            for (int j = 0; j < 5; j ++ )
                if (g[4][j] == '0')
                {
                    dark = true;
                    break;
                }
            if (!dark) res = min(res, step);
            memcpy (g, backup, sizeof g);
        }

        if(res > 6) res = -1;
        cout << res << endl;

    }
    return 0;
}
