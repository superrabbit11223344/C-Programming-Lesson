#include <stdio.h>
#include <math.h>

int main()
{
    freopen("data/ex90.in", "r", stdin);

    int n, h[101];
    int b[101][3] = {0};
    scanf("%d", &n); //要求的n道题
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    } //输入n道题
    int m, k;
    scanf("%d %d", &m, &k); //输入学生人数和所需前k名学生；
    for (int i = 1; i <= m; i++)
    {
        int p;
        scanf("%d %d", &b[i][1], &p); //输入学号用b[i][1]记住，p为该学生做的题总数
        for (int j = 1; j <= p; j++)
        {
            int r;
            scanf("%d", &r); // p次内循环，该生会做的题号
            for (int l = 1; l <= n; l++)
            {
                if (r == h[l])
                {
                    b[i][2] = b[i][2] + 1;
                    // break;
                } //题号相同，用b[i][2]加一来代替该生总分；
            }
        }
    }
    for (int i = 1; i <= m - 1; i++)
    {
        for (int j = m - 1; j >= i; j--)
        {
            if ((b[j][2] == b[j + 1][2] && b[j][1] > b[j + 1][1]) || b[j][2] < b[j + 1][2])
            {
                int term = b[j][2];
                int temp = b[j][1];
                b[j][2] = b[j + 1][2];
                b[j][1] = b[j + 1][1];
                b[j + 1][2] = term;
                b[j + 1][1] = temp;
            }
        }
    } //冒泡排序，已考虑成绩相同

    int t = 1; // t为变量，输出学号
    for (int i = 1; i <= k && t <= m; i++)
    {
        printf("%d ", b[t][1]); // 输出排名为i的第一个同学的学号
        // 输出成绩相同的同学学号
        while (b[t + 1][2] == b[t][2] && t <= m - 1)
        {
            printf("%d ", b[t + 1][1]);
            t += 1;
        }
        t += 1;
    }
}