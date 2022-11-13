#include <stdio.h>
#include <math.h> //

int main()
{
    // freopen("../data/ex128.in", "r", stdin);

    int n, m, final, line, k[5000], s[5000], i, j, z, z2, aver, sum = 0;

    scanf("%d %d\n", &n, &m); // n个选手，m个录取名额

    // 所有选手的报名号k和笔试成绩s
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &k[i], &s[i]);
    }

    // 按成绩从高到低排序
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (s[j] < s[j + 1])
            {
                z2 = s[j];
                s[j] = s[j + 1];
                s[j + 1] = z2;
                z = k[j];
                k[j] = k[j + 1];
                k[j + 1] = z;
            }
        }
    }

    // 按报名号从高到低排序
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (s[j] == s[j + 1])
            {
                if (k[j] > k[j + 1])
                {
                    z2 = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = z2;
                    z = k[j];
                    k[j] = k[j + 1];
                    k[j + 1] = z;
                }
            }
        }
    }

    // 进入面试的人数（题目要求下取整）
    final = floor(m * 1.5); // 这里用了floor函数，需要在开头引math.h的头文件
    // 按照录取人数的 150% 来划定最低分数线
    line = s[final - 1];
    // 这里不能写if，要改成while，因为可能有多个同学达到了最低分数线
    while (s[final - 1] == s[final])
    {
        final++;
    }
    for (i = 0; i < final - 1; i++)
    {
        for (j = 0; j < final - 1 - i; j++)
        {
            if (s[i] == s[i + 1])
            {
                if (k[i] > k[i + 1])
                {
                    z = k[i + 1];
                    k[i + 1] = k[i];
                    k[i] = z;
                }
            }
        }
    }

    // 输出结果
    if (n == m)
    {
        printf("%d %d", s[n], n);
        for (i = 0; i < n; i++)
        {
            printf("%d %d\n", k[i], s[i]);
        }
    }
    else
    {
        printf("%d %d\n", s[final - 1], final);
        for (i = 0; i < final; i++)
        {
            printf("%d %d\n", k[i], s[i]);
        }
    }
    return 0;
}