#include <stdio.h>
int main()
{
    freopen("../data/ex89.in", "r", stdin);

    int a[200], n;
    double b[200];
    int i, j;
    scanf("%d", &n);
    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d%lf", &a[i], &b[i]);
        }
    }
    int sum;
    scanf("%d", &sum); //输入结束
    if (sum <= 0)
    {
        printf("NO");
        return 0;
    }

    if (n == 0)
    {
        printf("0.00");
        return 0;
    }

    // n = 1的情况需要放在前面判断
    if (n == 1) {
        printf("%.2lf", sum * b[0]);
        return 0;
    }

    // else
    // {
    double jiang;
    jiang = 0.0;

    for (i = 0;; i++)
    {
        if (sum <= a[0] && sum > 0)
        {
            jiang = sum * b[0];
            break;
        }
        else if (sum >= a[i] && sum <= a[i + 1])
        {
            jiang = (sum - a[i]) * b[i + 1] + a[0] * b[0];
            for (j = i; j >= 1; j--)
            {
                jiang = jiang + (a[j] - a[j - 1]) * b[j];
            }
            break;
        } //分配方法的一种
    }

    if (sum > a[n - 2])
    {
        if (n >= 2)
        {
            jiang = (sum - a[n - 2]) * b[n - 1] + a[0] * b[0];
            for (j = n - 1; j >= 2; j--)
            {

                jiang = jiang + (a[j - 1] - a[j - 2]) * b[j - 1];
            }
        }

        if (n == 2)
        {
            jiang = (sum - a[1]) * b[2] + a[0] * b[0];
        }
        // else if (n == 1)
        // {
        //     jiang = sum * b[0];
        // }
    }

    printf("%.2lf", jiang);
    // } // else中的条件输入

    return 0;
}
