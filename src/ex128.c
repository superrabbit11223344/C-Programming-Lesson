#include <stdio.h>

int main()
{
    int n, m, x[5001][2], tem;
    scanf("%d %d", &n, &m);
    m = m * 1.5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
            scanf("%d", &x[i][j]);
    }
    for (int i = 1; i < n; i++)
    {
        int max = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (x[j][1] > x[max][1])
                max = j;
        }
        if (max != i)
        {
            tem = x[i][1];
            x[i][1] = x[max][1];
            x[max][1] = tem;
            tem = x[i][0];
            x[i][0] = x[max][0];
            x[max][0] = tem;
        }
    }
    int grade = x[m][1], t = m;
    if (x[m][1] == x[m + 1][1] && m != n)
    {
        int flag = 1;
        for (int j = m + 2; j <= n; j++)
        {
            if (x[m][1] == x[j][1])
                flag++;
            else
                break;
        }
        t = m + flag;
    }

    // 如果成绩相等，按学号从低往下排
    for (int i = 1; i < t;)
    {
        if (x[i][1] == x[i + 1][1])
        {
            int ship = 1;
            for (int j = i + 2; j <= t; j++)
            {
                if (x[i][1] == x[j][1])
                    ship++;
                else
                    break;
            }
            for (int a = i; a < i + ship; a++)
            {
                int min = a;
                for (int b = a + 1; b <= i + ship; b++)
                {
                    if (x[b][0] < x[min][0])
                        min = b;
                }
                if (min != a)
                {
                    tem = x[a][0];
                    x[a][0] = x[min][0];
                    x[min][0] = tem;
                }
            }
            i += ship + 1;
        }
        else i++;
    }

    printf("%d %d\n", grade, t);
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}