#include <stdio.h>
int main()
{
    freopen("data/ex90.in", "r", stdin);

    int n;  // 老师要求的题目个数
    scanf("%d", &n);

    int num[100];   // 老师要求的题目
    int i, j, s, l;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    int m, k;   // m个学生，老师希望找出刷题最多的k个同学
    scanf("%d%d", &m, &k);

    int sno[100];   // 同学的学号
    int p[100], a[100][100], count[100];    // p数组存的是每个同学刷了多少题，a数组存的是每个同学刷的题目编号，count表示每个同学的有效刷图数
    for (i = 0; i < m; i++) // count数组初始化
    {
        count[i] = 0;
    }

    for (i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            a[i][j] = -1;
        }
    }
    
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &sno[i], &p[i]);
        for (j = 0; j < p[i]; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    // 统计题目数不对！！
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p[i]; j++)
        {
            for (s = 0; s < n; s++)
            {
                if (a[i][j] == num[s])
                {
                    count[i]++;
                }
            }
        }
    }
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (count[j] < count[j + 1])
            {
                s = sno[j];
                sno[j] = sno[j + 1];
                sno[j + 1] = s;
                l = count[j];
                count[j] = count[j + 1];
                count[j + 1] = l;
            }
        }
    }

    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (count[j] == count[j + 1])
            {
                if (sno[j] > sno[j + 1])
                {
                    s = sno[j];
                    sno[j] = sno[j + 1];
                    sno[j + 1] = s;
                    l = count[j];
                    count[j] = count[j + 1];
                    count[j + 1] = l;
                }
            }
        }
    }

    int rank[100];
    rank[0] = 1;
    for (i = 1; i < m; i++)
    {
        rank[i] = rank[i - 1] + 1;
        if (count[i] == count[i - 1])
        {
            rank[i] = rank[i - 1];
        }
    }
    i = 0;
    while (rank[i] <= k && i < m)
    {
        printf("%d ", sno[i]);
        i++;
    }

    return 0;
}
