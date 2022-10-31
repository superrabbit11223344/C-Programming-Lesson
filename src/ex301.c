#include <stdio.h>
#include <math.h>
#include <string.h>


int main()
{
    // 从本地文件读测试用例，提交到OJ时去掉下面一行
    freopen("data/data10.in", "r", stdin);

    int n, m, g;    // 分别表示学生人数、分数段个数、需解决的任务编号
    scanf("%d %d %d", &n, &m, &g);
    int student[5002];
    int s;

    // 读入学生成绩
    for (s = 1; s <= n; s++)
    {
        scanf("%d", &student[s]);
    }

    int x = 100 / m;    // 分数段长度
    int ren[12], ren2[12];
    int i, j, k;
    // 分数段
    for (i = 1; i <= m; i++)
    {
        ren[i] = ren2[i] = 0;
    }
    for (i = 1; i <= m - 1; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (student[j] < x * i && student[j] >= x * (i - 1))
            {
                ren[i]++;
                ren2[i]++;
            }
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (student[j] <= 100 && student[j] >= 100 - x)
        {
            ren[m]++;
            ren2[m]++;
        }
    }

    if (g == 0 || g == 1)
    {
        int max, r;
        for (k = 1; k <= m; k++)
        {
            for (i = 1, max = -1; i <= m; i++)
            {
                if (max < ren[i])
                {
                    max = ren[i];
                    r = i;
                }
            }

            if (r == m)
            {
                printf("[%2d,%3d]: %d\n", 100 - x, 100, max);
            }
            else
            {
                printf("[%2d,%3d): %d\n", x * (r - 1), x * r, max);
            }

            ren[r] = -1;
            continue;
        }
        printf("\n");
    }

    if (g == 0 || g == 2)
    {
        int max = -1;
        for (j = 1; j <= m; j++)
        {
            max = (max >= ren2[j]) ? max : ren2[j];
        }
        if (max > 50)
        {
            double u = max / 50.0;
            for (i = 1; i <= m; i++)
            {
                if (ren2[i] == max) {
                    ren2[i] = 50;
                } else {
                    ren2[i] = floor(ren2[i] * 1.0 / u);
                }
            }
        }

        for (i = 1; i <= m - 1; i++)
        {
            printf("[%2d,%3d):", x * (i - 1), x * i);
            if (ren2[i] != 0)
            {
                for (j = 1; j <= ren2[i]; j++)
                {
                    printf("%c", '*');
                }
            }
            printf("\n");
        }
        printf("[%2d,%3d]:", 100 - x, 100);
        if (ren2[m] != 0)
        {
            for (j = 1; j <= ren2[m]; j++)
            {
                printf("%c", '*');
            }
            printf("\n");
        }
    }
    return 0;
}
