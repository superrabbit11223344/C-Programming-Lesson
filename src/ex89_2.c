#include <stdio.h>

int main()
{
    freopen("data/ex89.in", "r", stdin);

    int n, i, profit, f[105] = {0}, j, k;

    double sum = 0, rate[105] = {0};

    scanf("%d", &n);
    if (n == 0)
    {
        sum = 0;
        printf("%.2lf", sum);
    }
    else if (n == 1)
    {
        scanf("%d%lf%d", &f[1], &rate[1], &profit);

        sum += profit * rate[1];

        printf("%.2lf", sum);
    }

    else

    {
        for (i = 1; i < n; i++)
        { //从1开始

            scanf("%d%lf", &f[i], &rate[i]);
        }

        scanf("%d %lf", &f[n], &rate[n]); //-1的利率
                                          
        f[n] = 9000000;

        scanf("%d", &profit);

        if (profit < 0)
        {
            printf("NO");
            return 0;
        }

        if (n == 0)
        {
            printf("%.2f", 0.000);
            return 0;
        }

        // 注意：这里j有可能不存在，比如小于第一个边界值的情况
        for (i = 0; i < n; i++)
        {
            if (profit <= f[i + 1] && profit > f[i])
            {
                j = i;
                break;
            }
        } //找出利润在哪里

        if (j == 0) {
            sum += (profit - f[0]) * rate[1];
            printf("%.2lf", sum);
            return 0;
        }

        for (i = 0; i < n; i++)
        {

            sum += (f[i + 1] - f[i]) * rate[i + 1];

            if (i + 1 == j)

                break;

        } //算填满区间的那部分

        sum += (profit - f[j]) * rate[j + 1];

        printf("%.2lf", sum);
    }

    return 0;
}