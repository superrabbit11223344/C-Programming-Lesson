#include <stdio.h>

int main()
{
    freopen("data/ex142.in", "r", stdin);

    int m, n;
    scanf("%d%d", &m, &n);

    int k;
    scanf("%d", &k);
    int l[100];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &l[i]);
    }

    int a[100][100];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // 保证第一列是从小到大排序
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            if (a[j][0] > a[j + 1][0])
            {
                for (int p = 0; p < n; p++)
                {
                    int b = a[j][p];
                    a[j][p] = a[j + 1][p];
                    a[j + 1][p] = b;
                }
            }
        }
    }

    // 从次优先列向优先列的顺序，对数据进行排序
    for (int q = k - 1; q >= 0; q--)
    {
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < m - i - 1; j++)
            {
                if (a[j][l[q] - 1] > a[j + 1][l[q] - 1])
                {
                    for (int p = 0; p < n; p++)
                    {
                        int b = a[j][p];
                        a[j][p] = a[j + 1][p];
                        a[j + 1][p] = b;
                    }
                }
            }
        }
    }

    // 打印最终结果
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}