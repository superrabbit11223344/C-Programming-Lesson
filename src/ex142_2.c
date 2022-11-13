#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    freopen("../data/ex142.in", "r", stdin);

    int m, n;
    scanf("%d %d", &m, &n);
    int k;
    scanf("%d", &k);
    int row[MAX_SIZE];
    int i, j, l, s;
    l = 0;
    int temp = 0;
    for (i = 0; i < k; i++)
    {
        scanf("%d", &row[i]);
    }
    int matrix[MAX_SIZE][MAX_SIZE];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (matrix[j][row[l] - 1] > matrix[j + 1][row[l] - 1])
            {
                for (s = 0; s < n; s++)
                {
                    temp = matrix[j + 1][s];
                    matrix[j + 1][s] = matrix[j][s];
                    matrix[j][s] = temp;
                }
            }
        }
    }
    // 这里的排序逻辑不对，应该是row数组中第l列的所有数据都相等时，再按照l+1列进行排序
    for (l = 1; l < k; l++)
    {
        for (i = 0; i < m - 1; i++)
        {
            for (j = 0; j < m - i - 1; j++)
            {
                if (matrix[j][row[l - 1] - 1] == matrix[j + 1][row[l - 1] - 1])
                {
                    if (matrix[j][row[l] - 1] > matrix[j + 1][row[l] - 1])
                    {
                        for (s = 0; s < n; s++)
                        {
                            temp = matrix[j][s];
                            matrix[j][s] = matrix[j + 1][s];
                            matrix[j + 1][s] = temp;
                        }
                    }
                }
            }
        }
    }
    l = k - 1;
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
            if (matrix[j][row[l] - 1] == matrix[j + 1][row[l] - 1])
            {
                if (matrix[j][0] > matrix[j + 1][0])
                {
                    for (s = 0; s < n; s++)
                    {
                        temp = matrix[j][s];
                        matrix[j][s] = matrix[j + 1][s];
                        matrix[j + 1][s] = temp;
                    }
                }
            }
    }
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
